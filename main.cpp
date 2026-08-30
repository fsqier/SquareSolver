#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<windows.h>

#include "solver.h"
#include "solver.cpp"
#include "test_program.h"
#include "test_program.cpp"
#include "in_out.h"
#include "in_out.cpp"
#include "graphics.h"
#include "graphics.cpp"


int main() {

    SetWindow();

    if (NeedTest()) {
        RunAllTests();
    }

    txClearConsole();

    while (NeedContinue()) {
        txClearConsole();

        double a = 0, b = 0, c = 0;
        while (!InputCoef(&a, &b, &c)) {
            SlowPrint("Пожалуйста, давай еще раз:(\n");
        }

        double x1 = NAN, x2 = NAN;
        int CntRoots = SquareSolver(a, b, c, &x1, &x2);

        OutputSolves(CntRoots, x1, x2);

        ChooseColor(a, b, c);
        SlowPrint("Нажмите Esc чтоб продолжить\n");
        DrawGraph(a, b, c);

    }

    return 0;
}

