#include "graphics.h"
#include <TXlib.h>
#include <stdio.h>
#include <windows.h>

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
    txLine(CENTER_X, 0, CENTER_X, SIZE_Y);
    txLine(0, CENTER_Y, SIZE_X, CENTER_Y);

    //стрелка для Ох
    txLine(CENTER_X, 0, CENTER_X - 10, 30);
    txLine(CENTER_X, 0, CENTER_X + 10, 30);

    //стрелка для Оу
    txLine(SIZE_X, CENTER_Y, SIZE_X - 30, CENTER_Y - 10);
    txLine(SIZE_X, CENTER_Y, SIZE_X - 30, CENTER_Y + 10);

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


double OnWindow(double num, double center) {
    return (num * SCALE) + center;
}

void ChooseColor(double a, double b, double c) {

    SlowPrint("Write 3 nums: ");
    int r = 0, g = 0, bl = 0;
    scanf("%d %d %d", &r, &g, &bl);

    txSetColor(RGB(r, g, bl));

    DrawParabola(a, b, c);
}


void DrawParabola(double a, double b, double c) {

    double step = 0.1;
    double prevx = NAN, prevy = NAN;

    double min_x = -CENTER_X / SCALE;
    double max_x = CENTER_X / SCALE;

    for (double x = min_x; x < max_x; x += step) {
        double y = a * x * x + b * x + c;
        if (isnan(prevx)) {
            prevx = x;
            prevy = y;
            continue;
        }

        txLine(OnWindow(prevx, CENTER_X), OnWindow(-prevy, CENTER_Y),
        OnWindow(x, CENTER_X), OnWindow(-y, CENTER_Y));
        prevx = x;
        prevy = y;
    }
}
