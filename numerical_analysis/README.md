# Numerical analysis

## Calculating roots
- Bisection method.
- Newthon / Raphson method.

### How to use:
0. Modify the source code (functions f and/or g, gprime) according to your needs.
1. Run:
````
gcc root_function.c -o a; ./a
````
2. Choose a valid option according to your desired method.
3. Enter the required data by the algorithm.

## Solving linear equation systems.

The program solves a linear system Ax = b.

### How to use:
0. You need three different files for A, x and b.
1. Run:
````
make clean; make; ./linear_equation_solver
````
2. Choose a valid option according to your desired method.
3. Enter the required data by the algorithm.

### File examples:

#### (1) Small
You will find files:
- smallA (Matrix A)
- smallX (Initial approximation x)
- smallB (Solution vector B)

#### (2) Medium, size 886
You will find files:
- a886.dat (Matrix A)
- x886.dat (Initial approximation x)
- b886.dat (Solution vector B)
- solution886.dat (Real solution, for testing purposes

Suggested parameters:

With Jacobi:
- Tolerance: 0.00001.
- Maximum iterations: 3150.

With Gauss-Seidel:
- Tolerance: 0.00001.
- Maximum iterations: 1575.