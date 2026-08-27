#ifndef SOLVER_H
#define SOLVER_H

enum cnt_roots_t {
    INF_ROOTS = -1,
    NO_ROOTS  = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2
};


int    SquareSolver(double a, double b, double c, double* x1, double* x2);
int    SquareEq    (double a, double b, double c, double* x1, double* x2);
int    LineEq      (double b, double c, double* x1);
int    IsZero      (double num);


#define DISCR(a, b, c) ((b) * (b) - 4 * (a)*(c))

#endif
