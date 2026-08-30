#include "graphics.h"
#include <TXlib.h>
#include <stdio.h>
#include <windows.h>

void DrawGraph(double a, double b, double c) {

    txBegin();

    while(!GetAsyncKeyState (VK_ESCAPE)) {
        txSetFillColor(TX_WHITE);
        txClear();
        DrawAxes();

        DrawParabola(a, b, c);

        if (GetAsyncKeyState (VK_UP)) {
            OFFSET_Y -= SCALE;    
        }
        if (GetAsyncKeyState (VK_DOWN) and SCALE > 5) {
            OFFSET_Y += SCALE;
        }
        if (GetAsyncKeyState (VK_LEFT) and SCALE > 5) {
            OFFSET_X -= SCALE;
        }
        if (GetAsyncKeyState (VK_RIGHT) and SCALE > 5) {
            OFFSET_X += SCALE;
        }
        CENTER_X = SIZE_X / 2 + OFFSET_X;
        CENTER_Y = SIZE_Y / 2 + OFFSET_Y;


        txSleep(50);
    }

    txEnd();
    SCALE = 20.0;
    txSetFillColor(TX_WHITE);
    txClear();
    DrawAxes();
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
    txLine(CENTER_X,        0, CENTER_X,   SIZE_Y);
    txLine(       0, CENTER_Y,   SIZE_X, CENTER_Y);

    //стрелка для Ох
    txLine(CENTER_X, 0, CENTER_X - 10, 30);
    txLine(CENTER_X, 0, CENTER_X + 10, 30);

    //стрелка для Оу
    txLine(SIZE_X, CENTER_Y, SIZE_X - 30, CENTER_Y - 10);
    txLine(SIZE_X, CENTER_Y, SIZE_X - 30, CENTER_Y + 10);

    // деления на Ох
    for (double x = SCALE; x < SIZE_X; x += SCALE) {
        txLine(x, CENTER_Y - 10, x, CENTER_Y + 10);
    }

    // деления на Оу
    for (double y = SCALE; y < SIZE_Y; y += SCALE) {
        txLine(CENTER_X - 10, y, CENTER_X + 10, y);
    }
}


double OnWindow(double num, double center) {
    return (num * SCALE) + center;
}

void ChooseColor(double a, double b, double c) {

    SlowPrint("Write 3 nums: ");
    int red = 0, green = 0, blue = 0;
    scanf("%d %d %d", &red, &green, &blue);

    txSetColor(RGB(red, green, blue));

    DrawParabola(a, b, c);
}


void DrawParabola(double a, double b, double c) {

    double step = 0.01;
    double prevx = NAN, prevy = NAN;

    double min_x = -100.0;
    double max_x =  100.0;

    for (double x = min_x; x < max_x; x += step) {
        double y = a * x * x + b * x + c;
        if (isnan(prevx)) {
            prevx = x;
            prevy = y;
            continue;
        }

        txLine(OnWindow(prevx, CENTER_X), OnWindow(-prevy, CENTER_Y),
              OnWindow(     x, CENTER_X), OnWindow(    -y, CENTER_Y));
        prevx = x;
        prevy = y;
    }
}
