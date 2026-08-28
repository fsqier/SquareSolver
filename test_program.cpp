#include <TXlib.h>
#include "test_program.h"
#include "solver.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>


void RunAllTests() {

    int cnt_correct_test = 0,  cnt_all_test = 0;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int CntRoots = 0;

    FILE* fp = fopen("tests.txt", "r");
    assert(fp != NULL);

    while ((fscanf(fp, "%lg %lg %lg %d %lg %lg", &a, &b, &c, &CntRoots, &x1, &x2)) != EOF) {
        if (CntRoots == NO_ROOTS or CntRoots == INF_ROOTS) {
            x1 = NAN;
            x2 = NAN;
        } else if (CntRoots == ONE_ROOT) {
            x2 = NAN;
        }
        CntTest(a, b, c, CntRoots, x1, x2, &cnt_all_test, &cnt_correct_test);
    }

    fclose(fp);

    printf("Пройдено %d/%d\n", cnt_correct_test, cnt_all_test);
}

void CntTest (double a, double b, double c, int CntRoot,
            double x1, double x2, int* cnt_all_test, int* cnt_correct_test) {

    ++(*cnt_all_test);
    *cnt_correct_test += CorrectTest(a, b, c, CntRoot, x1, x2);
}


int CorrectTest (double a, double b, double c, int CntRoot, double x1, double x2) {

    TestValRef test = {
        .a = a,
        .b = b,
        .c = c,
        .CntRoots = CntRoot,
        .x1 = x1,
        .x2 = x2
    };
    return RunOneTest(test);
}


int RunOneTest(TestValRef test) {

    double x1 = NAN, x2 = NAN;
    int CntRoots = SquareSolver(test.a, test.b, test.c, &x1, &x2);

    if (CorrectAns(test, CntRoots, x1, x2)) {
        printf("\033[32mTest Ok: \033[0ma = %lg, b = %lg, c = %lg\n",
                test.a, test.b, test.c);
        return true;
    }

    printf("\033[31mTest FALLED: a = %lg, b = %lg, c = %lg\n"
            "Expected: %d roots x1ref = %lg, x2ref = %lg\n"
            "Get:      %d roots x1    = %lg, x2    = %lg\n\033[0m",
            test.a, test.b, test.c, test.CntRoots, test.x1, test.x2, CntRoots, x1, x2);
    return false;
}


int CorrectAns(TestValRef test, int CntRoots, double x1, double x2) {

    if (CntRoots != test.CntRoots) {
        return false;
    }

    if (CntRoots == ONE_ROOT && IsZero(x1 - test.x1) && isnan(x2)) {
        return true;
    }

    if (CntRoots == TWO_ROOTS) {
        double max_ref_root = MAX(test.x1, test.x2), max_get_root = MAX(x1, x2);
        double min_ref_root = MIN(test.x1, test.x2), min_get_root = MIN(x1, x2);
        if (IsZero(max_ref_root - max_get_root) && IsZero(min_ref_root - min_get_root)) {
            return true;
        }
    }

    if ((CntRoots == INF_ROOTS || CntRoots == NO_ROOTS) && isnan(x2) &&  isnan(x1)) {
        return true;
    }

    return false;
}

