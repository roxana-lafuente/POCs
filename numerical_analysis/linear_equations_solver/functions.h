#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* Method 1: Jacobi */
double *
jacobi(double **a, double *b, double *x, double delta, int N, int MAX_ITE);

/* Method 2: Gauss - Seidel */
double *
gaussseidel(double **a, double *b, double *x, double delta, int N, int MAX_ITE);

#endif