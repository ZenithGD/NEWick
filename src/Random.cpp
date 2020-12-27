#include <cstdlib>
#include <ctime>

#include <Random.hpp>

// genera un entero aleatorio entre l_b y h_b
int rand_int(const int l_b, const int h_b) {
	return rand() % (h_b - l_b + 1) + l_b; 
}

// genera un real aleatorio entre l_b y h_b
double rand_double(const double l_b, const double h_b) {
	return (double)rand() / (double)RAND_MAX * (h_b - l_b) + l_b;
}