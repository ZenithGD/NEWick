#ifndef NWK_NODE
#define NWK_NODE

#include <iostream>

// Nodo newick con nombre y distancia
struct nwk_node {
	std::string nom;
	double dist;
};

// Imprimir nodo newick
std::ostream& operator<<(std::ostream& f, const nwk_node& n);

/* Pre: h_b > l_b
 * Post: Genera un nodo con distancia de newick aleatoria entre l_b y h_b,
 * 		 y tiene una posibilidad ("sp_perc" * 100) % de que el nodo generado
 * 		 comience por la subcadena "special".
 */
nwk_node rand_node( const int id, const double l_b, const double h_b, 
					const double sp_perc, const std::string special );

#endif