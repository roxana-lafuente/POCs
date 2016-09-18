#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include "functions.h"
#include "read_file.h"


/* Summation */
double
summation(int i, int N, double **a, double *x){
    int j = 0;
    double sum = 0.00;

    for (j=0;j<N;j++){
        if (i != j)
            sum = a[i][j] * x[j] + sum;
    }

    return sum;
}


double *
mult(double **a, double *x, int N){
    int o = 0, m = 0;
    double *t = calloc(N, sizeof(double));

    for (o = 0; o < N; o++){
        for(m = 0; m < N; ++m){
            t[o] = a[o][m] * x[m] + t[o];
        }
    }

    return t;
}


double
get_norm(double *u, double *x, int N){
    int j = 0;
    double n = 0.00;

    for (j = 0; j < N; j++){
        n = fabs(u[j] - x[j]) + n;
    }

    return n;
}


/* Method 1: Jacobi */
double *
jacobi(double **a, double *b, double *x, double delta, int N, int MAX_ITE){
    int s = 0, i = 0, m = 0;
    double norm = 0.00;
    double *u = calloc (N, sizeof(double));
    bool flag = true;

    for(s = 0; s < MAX_ITE && flag; s++){
        for (i = 0; i < N; i++){
            u[i] = (b[i] - summation(i, N, a, x)) / a[i][i];
        }

        norm = get_norm(u, x, N);
        flag = norm > delta;

        for (m = 0; m < N; m++){
            x[m] = u[m];
        }

        printf("The %dº approximation is: \n", (s+1));
        show_vector(u, N);
        printf("The norm is: %lf\n", norm);
        printf("\n");
    }
    free(u);
    return(x);
}

/* Method 2: Gauss - Seidel */
double *
gaussseidel(double **a, double *b, double *x, double delta, int N, int MAX_ITE){
    int s = 0, i = 0;
    double norm = 0.00;
    double *u = calloc (N, sizeof(double));
    bool flag = true;

    for(s = 0; s < MAX_ITE && flag; s++){
        for (i = 0; i < N; i++){
            u[i] = x[i];
        }

        for (i = 0; i < N; i++){
            x[i] = (b[i] - summation(i, N, a, x)) / a[i][i];
        }

        norm = get_norm(x, u, N);
        flag = norm > delta;

        printf("The %dº approximation is: \n", (s+1));
        show_vector(u, N);
        printf("The norm is: %lf\n", norm);
        printf("\n");
    }
    free(u);
    return(x);
}