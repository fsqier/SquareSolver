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


const double SIZE_X = 600;
const double SIZE_Y = 600;
const double SCALE = 20;

void   SetWindow    ();
void   DrawAxes     ();
void   DrawParabola (double a, double b, double c);
double OnWindow     (double num, double size);
void   ChooseColor  (double a, double b, double c);


int main() {

    SetWindow();

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

        ChooseColor(a, b, c);

        OutputSolves(CntRoots, x1, x2);

        txClearConsole();
    }

    return 0;
}

void SetWindow() {

    txCreateWindow(SIZE_X, SIZE_Y);
    txSetFillColor(TX_WHITE);
    txClear();
    txClearConsole();
    DrawAxes();
}

void DrawAxes() {

    txSetColor(TX_BLACK, 1);
    //оси
    txLine(SIZE_X / 2, 0, SIZE_X / 2, SIZE_Y);
    txLine(0, SIZE_Y / 2, SIZE_X, SIZE_Y / 2);

    //стрелка для Ох
    txLine(SIZE_X / 2, 0, SIZE_X / 2 - 10, 30);
    txLine(SIZE_X / 2, 0, SIZE_X / 2 + 10, 30);

    //стрелка для Оу
    txLine(SIZE_X, SIZE_Y / 2, SIZE_X - 30, SIZE_Y / 2 - 10);
    txLine(SIZE_X, SIZE_Y / 2, SIZE_X - 30, SIZE_Y / 2 + 10);

    // деления на Ох
    for (double x = SCALE; x < SIZE_X; x += SCALE) {
        txLine(x, 290, x, 310);
        //txTextOut(x, 280, "1");
    }

    // деления на Оу
    for (double y = SCALE; y < SIZE_Y; y += SCALE) {
        txLine(290, y, 310, y);
    }
}


double OnWindow(double num, double size) {
    return (num * SCALE) + size / 2.0;
}

void ChooseColor(double a, double b, double c) {

    printf("Напиши 3 числа: ");
    int r = 0, g = 0, bl = 0;
    scanf("%d %d %d", &r, &g, &bl);
    txColor(r, g, bl);

    DrawParabola(a, b, c);
}


void DrawParabola(double a, double b, double c) {

    double step = 0.1;
    double prevx = NAN, prevy = NAN;

    for (double x = -SIZE_X / SCALE / 2; x < SIZE_X / SCALE / 2; x += step) {
        double y = a * x * x + b * x + c;
        if (OnWindow(y, SIZE_Y) < 0.0 or OnWindow(y, SIZE_Y) > 600.0) {
            continue;
        } else if (isnan(prevx)) {
            prevx = x;
            prevy = y;
            continue;

        txLine(OnWindow(prevx, SIZE_X), OnWindow(-prevy, SIZE_Y),
        OnWindow(x, SIZE_X), OnWindow(-y, SIZE_Y));
        prevx = x;
        prevy = y;

    }
}
