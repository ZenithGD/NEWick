#include <iostream>
#include <string>
#include <NewickNode.hpp>
#include <Random.hpp>

// Imprimir nodo newick
std::ostream& operator<<(std::ostream& f, const nwk_node& n) {
	f << n.nom << ":" << n.dist;
	return f;
}

// genera un nodo aleatorio con posibilidad ("sp_perc" * 100) % de comenzar por la subcadena "special".
nwk_node rand_node(const int id, const double l_b, const double h_b, const double sp_perc, const std::string special) {
	nwk_node n;
	double uniform_01 = rand_double(0.0, 1.0);
	if ( uniform_01 < sp_perc ) {
		n.nom = special + std::to_string(id);
	}
	else {
		n.nom = "id" + std::to_string(id);
	}
	n.dist = rand_double(l_b, h_b);
	return n;
}