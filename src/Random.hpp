#ifndef RAND_H
#define RAND_H

/* Pre: h_b > l_b
 * Post: Genera un entero aleatorio entre l_b y h_b
 */
int rand_int(const int l_b, const int h_b);

/* Pre: h_b > l_b
 * Post: Genera un número real aleatorio entre l_b y h_b
 */
double rand_double(const double l_b, const double h_b);

#endif