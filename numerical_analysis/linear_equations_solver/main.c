#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "read_file.h"

#define TXTCOLOR "\033[0;40;32m"
#define NORMAL "\033[0m"

int
main (void) {
    double **a;
    double *b, *x;
    double delta = 0.00;
    int MAX_ITE = 0, op = 0, n = 0;

    while (op != 3){
        printf("\n***************************************\n");
        printf("*   %sLinear system equation solver%s   *\n", TXTCOLOR, NORMAL);
        printf("***************************************\n");
        printf("*      Choose the solver method:      *\n");
        printf("***************************************\n");
        printf("* %s1%s- Jacobi                           *\n", TXTCOLOR, NORMAL);
        printf("* %s2%s- Gauss-Seidel                     *\n", TXTCOLOR, NORMAL);
        printf("* %s3%s- Exit                             *\n", TXTCOLOR, NORMAL);
        printf("***************************************\n");
        printf("\n");
        scanf("%d", &op);

        switch (op){
            case 1: {
                char * MATRIZ = calloc (30, sizeof(char));
                char * VECTOR = calloc (30, sizeof(char));
                char * SOLUCION = calloc (30, sizeof(char));
                double * tmp;

                printf("Enter admitted tolerance: \n");
                scanf("%lf", &delta);
                printf("Enter maximum number of iterations allowed: \n");
                scanf("%d", &MAX_ITE);
                printf("Enter the filename which contains the matrix: \n");
                scanf("%s", MATRIZ);
                printf("Enter the filename which contains the initial approximation to the solution: \n");
                scanf("%s", VECTOR);
                printf("Enter the filename which contains the solution vector: \n");
                scanf("%s", SOLUCION);
                printf("\n");

                n = get_matrix_size(MATRIZ);
                a = read_matrix (MATRIZ);
                b = read_vector (VECTOR, n);
                x = read_vector (SOLUCION, n);

                tmp = jacobi(a, x, b, delta, n, MAX_ITE);

                printf("The final approximation to the solution is: \n");
                show_exponential_vector (tmp, n);
                printf("\n");

                destroy_matrix(a, n);
                free(tmp);
                free(x);
                free(MATRIZ);
                free(VECTOR);
                free(SOLUCION);
            }
            break;

            case 2: {
                char * MATRIZ = calloc (30, sizeof(char));
                char * VECTOR = calloc (30, sizeof(char));
                char * SOLUCION = calloc (30, sizeof(char));
                double * tmp;

                printf("Enter admitted tolerance: \n");
                scanf("%lf", &delta);
                printf("Enter maximum number of iterations allowed: \n");
                scanf("%d", &MAX_ITE);
                printf("Enter the filename which contains the matrix: \n");
                scanf("%s", MATRIZ);
                printf("Enter the filename which contains the initial approximation to the solution: \n");
                scanf("%s", VECTOR);
                printf("Enter the filename which contains the solution vector: \n");
                scanf("%s", SOLUCION);
                printf("\n");

                n = get_matrix_size(MATRIZ);
                a = read_matrix (MATRIZ);
                b = read_vector (VECTOR, n);
                x = read_vector (SOLUCION, n);

                tmp = gaussseidel(a, x, b, delta, n, MAX_ITE);

                printf("The final approximation to the solution is: \n");
                show_exponential_vector (x, n);
                printf("\n");

                destroy_matrix(a, n);
                free(x);
                free(tmp);
                free(MATRIZ);
                free(VECTOR);
                free(SOLUCION);
            }
            break;

            case 3: {
                op = 3;
                printf("Successfully exited. \n");
            }

        }
    }
    return 0;
}
