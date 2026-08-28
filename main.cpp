#include <TXLib.h>
#include <stdio.h>

#include "solver.h"
#include "solver.cpp"
#include "test_program.h"
#include "test_program.cpp"
#include "in_out.h"
#include "in_out.cpp"


int main() {

    txCreateWindow (800, 800);
    txSetFillColor (TX_WHITE);
    txClear ();
    txClearConsole();

    if (NeedTest()) {
        RunAllTests();
    }

    txClearConsole();

    while (NeedContinue()) {

        double a = 0, b = 0, c = 0;
        while (!InputCoef(&a, &b, &c)) {
            printf("Пожалуйста, давай еще раз:(\n");
        }

        double x1 = NAN, x2 = NAN;
        int CntRoots = SquareSolver(a, b, c, &x1, &x2);

        OutputSolves(CntRoots, x1, x2);
    }

    return 0;
}


