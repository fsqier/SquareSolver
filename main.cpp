/*!
@mainpage SquareSolver Документация
Это программа для решения квадратного уравнения.
Здесь реализованы решение, генерация тестов и само тестирование программы
*/


#include <stdio.h>
#include <TXLib.h>

#include "test_program.h"
#include "solver.h"
#include "in_out.h"


int main() {

    if (NeedTest()) {
        RunAllTests();
    }

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

