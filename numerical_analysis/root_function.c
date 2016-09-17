#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#define TXTCOLOR "\033[0;40;32m"
#define NORMAL "\033[0m"

/*
 * Function that we want to find the zeros of
 * Example: x = tan(x)-2*x;
 */
double
f (double x){
  x = x*x-3;
  return x;
}

/* Determines the sign of a double number */
int
sgn (const double real){
    int sgn=0;
    if (real>0)
        sgn=1;
    if (real<0)
        sgn=-1;
    return sgn;
}


/* Algorithm 1: Bisection method */
double
biseccion (double a, double b, const double epsilon){
    double c = 0.00;

    /* Half of the interval */
    c = a + (b - a) / 2.00;

    /* Redefines a and/or b according to the sign of f(c) */
    if (sgn(f(a)) != sgn(f(c)))
        b = c;
    if (sgn(f(c)) != sgn(f(b)))
        a = c;

    /* Termination condition */
    if (fabs(f(c))<epsilon){
        printf("\nThe value of f(%lf) is %0.0lf\n", c, abs(f(c)));
        return c;
    }
    else{
        printf("%lf, ", c);
        return biseccion(a,b,epsilon);
    }
}


/* Function g for Newton method */
double
g (const int r, double x){
    x= x*x*x-r;
    return x;
}

/* Derivate of g */
double
gprima (double x){
    x = 3.00*x*x;
    return x;
}

void
newton(double r, double xnext, double epsilon, int MAX_ITE){
    int n = 0;
    double x = 0.00;
    while (fabs(xnext-x)/fabs(xnext)>=epsilon && fabs(g(r,xnext))>=epsilon && n<MAX_ITE){
        x = xnext;
        xnext = x - (g(r,x) / gprima(x));
        n ++;
    }

    printf("El numero de iteraciones realizadas es: %d\n", n);
    printf("El valor final de la aproximacion de la raiz es: %lf\n", xnext);
    printf("El error relativo es: %lf\n", fabs(xnext-x)/(float)fabs(xnext));
    printf("El valor de |f(%lf)| es: %lf\n", xnext, g(r,xnext));
}

int
main(void){
    int op=0;

    while (op!=3){
        printf("\n*****************************************\n");
        printf("*  %sNumerical analysis - Finding roots%s   *\n", TXTCOLOR, NORMAL);
        printf("*****************************************\n");
        printf("*            Enter an option            *\n");
        printf("*****************************************\n");
        printf("* %s1%s - Bisection method                  *\n", TXTCOLOR, NORMAL);
        printf("* %s2%s - Newton method                     *\n", TXTCOLOR, NORMAL);
        printf("* %s3%s - Exit                              *\n", TXTCOLOR, NORMAL);
        printf("*****************************************\n");
        printf("\n");
        scanf("%d", &op);

        switch (op){

            case 1: {
                /* Bisection method */
                double a = 0.00, b = 0.00, epsilon = 0.00;

                printf("Enter initial interval:\n");
                scanf ("%lf", &a);
                scanf ("%lf", &b);
                while (a >= b || sgn(f(a)) == sgn(f(b))){
                    printf("The entry is not a valid interval. ");
                    printf("Please enter initial interval:\n");
                    scanf ("%lf", &a);
                    scanf ("%lf", &b);
                }

                printf("Enter admitted tolerance:\n");
                scanf("%lf", &epsilon);

                /* If entry if correct, call bisection. Otherwise print error. */
                assert(a < b && sgn(f(a)) != sgn(f(b)));
                printf("The succession of approximations to the root are: ");
                biseccion(a,b,epsilon);
            }
            break;

            case 2: {
                /* Newton - Raphson method */

                int MAX_ITE = 0;
                double xnext = 0.00, epsilon = 0.00, r = 0;

                printf("Enter a positive number to calculate its root:\n");
                scanf("%lf", &r);
                while (r <= 0){
                    printf("Wrong entry. Please enter a positive number to calculate its cubic root:\n");
                    scanf("%lf", &r);
                }
                assert(r > 0);

                printf("Enter an initial approximation of the root:\n");
                scanf("%lf", &xnext);

                printf("Enter the admitted tolerance:\n");
                scanf("%lf", &epsilon);

                printf("Enter the maximum number of iterations allowed:\n");
                scanf("%d", &MAX_ITE);

                newton(r, xnext, epsilon, MAX_ITE);
            }
            break;

            case 3: {
                printf("\n Exited successfully. \n");
            }
            break;
        }
    }
    return(0);
}