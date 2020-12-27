#ifndef NWK_TREE_H
#define NWK_TREE_H

#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>

#include <NewickNode.hpp>
#include <Random.hpp>

using namespace std;

// Clase que representa un árbol filogenético genérico (modelado mediante un árbol N-ario)
template <typename T>
class NewickTree {

	private:
		struct TreeNode { // primogénito - sig. hermano
			TreeNode* pri; // primer hijo
			TreeNode* sig; // siguiente hermano
			T val;
		};
		TreeNode* r;
		int n;

		/* Pre: -
		 * Post: Inserta un nuevo nodo con valor "val" de manera aleatoria
		 * 		 formando una nueva hoja, a partir del árbol cuya raíz es
		 * 		 apuntada por "pt"
		 */
		void insertAux(TreeNode*& pt, T val);
		/* Pre: pt != nullptr
		 * Post: Imprime el árbol cuya raíz es apuntada por "pt"
		 * 		 siguiendo el formato Newick por el flujo "out"
		 */
		void printAux(TreeNode* pt, ofstream& out);
		/* Pre: -
		 * Post: Imprime el bosque cuyo primer árbol es apuntado por "pt"
		 * 		 siguiendo el formato Newick por el flujo "out"
		 */
		void printForest(TreeNode* pt, ofstream& out);
	public:
		// Constructor de un árbol newick con anchura máxima N
		NewickTree(const int N);
		
		// Destructor (deberá liberar la memoria dinámica ocupada por el árbol)
		~NewickTree(); // no olvidar borrar memoria

		/* Pre: -
		 * Post: Inserta un nuevo nodo cuyo valor es "val" en una hoja
		 * 		 aleatoria del árbol
		 */
		void InsertRand(T val);

		/* Pre: -
		 * Post: Imprime por el flujo "out" la cadena en formato Newick que representa
		 * 		 a este árbol.
		 * 		 Por ejemplo el siguiente árbol
		 * 
		 * 			  |--0.3-----C
		 * 		A ----|
		 * 			  |--0.5-----B
		 * 
		 * 		 en formato Newick vendrá representado por la cadena (C:0.3,B:0.5)A;
 		 */
		void printTree(ofstream& out);
};

void printNode(const nwk_node& n) {
	cout << n.nom << ":" << n.dist << endl; 
}

template<typename T>
NewickTree<T>::NewickTree(const int N) 
{
	r = nullptr;
	n = N;
}

template<typename T>
NewickTree<T>::~NewickTree() 
{
	// to do
}

template<typename T>
void NewickTree<T>::insertAux(typename NewickTree<T>::TreeNode*& pt, T val){
	if ( pt == nullptr ) {
		pt = new typename NewickTree<T>::TreeNode;
		pt->pri = nullptr;
		pt->sig = nullptr;
		pt->val = val;
	}
	else {
		int r = rand() % n + 1; 
		typename NewickTree<T>::TreeNode* ptAux = pt;
		for ( int i = 0; i < r && ptAux->sig != nullptr; i++ ) {
			ptAux = ptAux->sig;
		}
		if ( ptAux->sig == nullptr ) {
			insertAux(ptAux->sig, val);
		}
		else {
			insertAux(ptAux->pri, val);
		}
	}
}

template<typename T>
void NewickTree<T>::printAux(typename NewickTree<T>::TreeNode* pt, ofstream& out) 
{
	if ( pt->pri != nullptr ) {
		out << "(";
		printForest(pt->pri, out);
		out << ")";
	}
	out << pt->val;
}

template<typename T>
void NewickTree<T>::printForest(TreeNode* pt, ofstream& out) 
{
	while( pt != nullptr ) {
		printAux(pt, out);
		if ( pt->sig != nullptr ) {
			out << ",";
		}
		pt = pt->sig;
	}
}

template<typename T>
void NewickTree<T>::InsertRand(T val) 
{
	if ( r == nullptr ) {
		r = new typename NewickTree<T>::TreeNode;
		r->pri = nullptr;
		r->sig = nullptr;
		r->val = val;
	}
	else {
		insertAux(r->pri, val);
	}
}

template<typename T>
void NewickTree<T>::printTree(ofstream& out) 
{
	if ( r != nullptr ) {
		printAux(r, out);
	}
	out << ";";
}

#endif