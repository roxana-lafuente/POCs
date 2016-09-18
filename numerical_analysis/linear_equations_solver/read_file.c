#include <stdio.h>
#include <stdlib.h>
#include "read_file.h"

int
get_matrix_size (const char* filename){
    FILE* file;
    int tam = 0;

    file = fopen(filename, "r");
    fscanf(file, "%d", &tam);
    fclose(file);

    return tam;
}

double **
read_matrix(const char* filename) {
    FILE* file;
    double ** a;
    int size, i, j;

    file = fopen(filename,"r");

    if (file == NULL) {
        return NULL;
    }

    fscanf(file, "%d", &size);

    a = calloc(size, sizeof(double**));

    if (a == NULL) {
        printf("Out of memory\n");
        return NULL;
    }

    for (i = 0; i < size; i = i+1)	{
        a[i] = calloc(size, sizeof(double));
        if (a[i] == NULL) {
            for (i = i - 1; i >= 0; i = i-1) {
                free(a[i]);
        }
        free(a);
        return NULL;
        }
    }	

    for (i = 0; i < size; i = i+1) {
        for (j = 0; j < size; j = j+1) {
            fscanf(file, "%lf", &a[i][j]);
        }
    }

    fclose(file);

    return a;
}

void
show_matrix (double ** a, int h) {
    int k = 0, l = 0;

    for (k = 0; k < h; k++) {
        l = 0;
        for (l = 0; l < h; l++) {
            printf ("%lf ", a[k][l]);
        }
        printf ("\n");
    }
}


double *
read_vector (char *filename, int tam) {
    FILE* file;
    double * v;
    int i = 0;

    file = fopen(filename,"r");
    if (file == NULL) {
        printf ("Error. Cannot open file %s", filename);
        return NULL;
    }
    fscanf(file, "%d", &tam);
    v = calloc(tam, sizeof(double*));
    if (v == NULL) {
        printf("Out of memory for %s\n", filename);
        return NULL;
    }

    for (i = 0; i < tam; i = i+1) {
        fscanf(file, "%lf", &v[i]);
    }

    fclose(file);

    return v;
}


void
show_vector (double * v, int h) {
    int k = 0;

    for (k = 0; k < h; k++) {
        printf("%lf \n", v[k]);
    }
}

/* Fix comma format: 1.350000
 * Exponential format: 1.350000e+00
 */
void
show_exponential_vector (double * v, int h) {
    int k = 0;

    for (k = 0; k < h; k++) {
        printf("%.10e \n", v[k]);
    }
}


void
destroy_matrix(double ** a, int size){
    int i = 0;
    for (i = 0; i < size; i = i + 1){
        free(a[i]);
    }
    free(a);
}
