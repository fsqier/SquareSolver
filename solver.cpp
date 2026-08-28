#include "solver.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>



int SquareSolver(double a, double b, double c, double* x1, double* x2) {

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if (IsZero(a)) {
        return LineEq(b, c, x1);
    }

    return SquareEq(a, b, c, x1, x2);
 }


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


 int IsZero(double num) {

    const double eps = 1e-2;

    if (num < eps && num > -eps) {
        return true;
    }
    return false;
 }
