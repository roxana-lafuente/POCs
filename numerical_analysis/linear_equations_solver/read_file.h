#ifndef READFILE_H
#define READFILE_H

int
get_matrix_size (const char* filename);

double **
read_matrix(const char* filename);

void
show_matrix (double ** a, int h);

double *
read_vector (char *filename, int tam);

void
show_vector (double * v, int h);

void
show_exponential_vector (double * v, int h);

void
destroy_matrix(double ** a, int size);

#endif
