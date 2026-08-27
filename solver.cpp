#include "solver.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>


//возвращает количество решений
int SquareSolver(double a, double b, double c, double* x1, double* x2) {

    if (IsZero(a)) {
        return LineEq(b, c, x1);
    }

    return SquareEq(a, b, c, x1, x2);
 }

//решение квадратного уравнения при a != 0
int SquareEq(double a, double b, double c, double* x1, double *x2) {

    if (IsZero(b)) {
        if (-c/a >= 0) {
            *x1 = sqrt(-c/a);
            return ONE_ROOT;
        }
        return NO_ROOTS;
    }

    if (IsZero(c)) {
        *x1 = 0;
        *x2 = -b/a;
        return TWO_ROOTS;
    }

    double d = DISCR(a, b, c);

    if (d < 0) {
        return NO_ROOTS;
    } else if (IsZero(d)) {
        *x1 = -b / (2*a);
        return ONE_ROOT;
    }

    double root = sqrt(d);
    *x1 = (-b + root) / (2*a);
    *x2 = (-b - root) / (2*a);
    return TWO_ROOTS;
 }

 //решение линейных уравнений
 int LineEq(double b, double c, double* x1) {

    if (IsZero(b)) {
        if (IsZero(c)) {
            return INF_ROOTS;
        }
        return NO_ROOTS;
    }

    *x1 = -c/b;
    return ONE_ROOT;
 }

 //сравнение double с 0
 int IsZero(double num) {

    if (num < eps && num > -eps) {
        return true;
    }
    return false;
 }
