#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>

#include <NewickTree.hpp>
#include <Random.hpp>
#include <NewickNode.hpp>

using namespace std;

// argv[1] = nº de nodos totales, argv[2] = aridad del árbol, argv[3] = fichero de salida
int main(int argc, char* argv[]) {

	if ( argc != 3 && argc != 4 ) {
		cout << "Nº argumentos inválidos, invocar como:" << endl;
		cout << "\t <ejecutable> <num_nodos> <n> " << endl;
		cout << "o bien" << endl;
		cout << "\t <ejecutable> <num_nodos> <n> <fichero_salida>" << endl;
		exit(1);
	}

	srand(time(nullptr));
	NewickTree<nwk_node> nwk(atoi(argv[2]));
	for ( int i = 0; i < atoi(argv[1]); i++ ) {
		nwk_node nw_r = rand_node(i, 0.0, 40.0, 0.3, "Spain");
		nwk.InsertRand(nw_r);
	}

	ofstream out;

	if ( argc == 3 ) {
		out.open("tree.nwk");
	}
	else {
		out.open(argv[3]);
	}

	if ( out.is_open() ) {
		nwk.printTree(out);
		out.close();
		return 0;
	}
	else {
		cout << "Error" << endl;
		return 1;
	}
}