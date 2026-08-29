#include "in_out.h"
#include "solver.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

void SlowPrint(const char* text) {

    const int TimeToSleep = 50;

    for (unsigned int i = 0; i < strlen(text); ++i) {
        Sleep(TimeToSleep);
        printf("%c", text[i]);
    }
}


 void OutputSolves(int CntRoots, double x1, double x2) {

    SlowPrint("Количество корней: ");

    switch(CntRoots) {
        case INF_ROOTS:
            SlowPrint("Бесконечно много\n");
            break;
        case NO_ROOTS:
            SlowPrint("0\n");
            break;
        case ONE_ROOT:
            printf("1\nx: %lg\n", x1);
            break;
        case TWO_ROOTS:
            printf("2\nx1: %lg, x2: %lg\n", x1, x2);
            break;
        default:
            SlowPrint("Корней почему-то больше двух и меньше INF\n");
            break;
    }
 }


int NeedContinue() {

    SlowPrint("Продолжить?(yes/no) ");
    return YesOrNo();
}


 int CheckInput(char* CodeWord, int WrongSymb) {

    if ((!strcmp(CodeWord, YES) || !strcmp(CodeWord, NO)) && !WrongSymb) {
        return true;
    }

    return false;
 }


int InputCoef(double* a, double* b, double* c) {

    SlowPrint("Введите коэффициенты:");
    int CorrectCoefs = scanf("%lg %lg %lg", a, b, c);
    int CntWrongSymb = ClearBuf();

    if (CorrectCoefs != ALL_CORRECT_COEFS || CntWrongSymb > 0) {
        return false;
    }

    printf("a: %lg, b: %lg, c: %lg\n", *a, *b, *c);

    return true;
}


int ClearBuf() {

    int CntWrongSymb = 0;
    int ch = getchar();
    while (ch != '\n') {
        if (ch != ' ') {
            ++CntWrongSymb;
        }
        ch = getchar();
    }

    return (CntWrongSymb > 0);
 }

int NeedTest() {

    SlowPrint("Нужно тестирование?(yes/no) ");
    return YesOrNo();
}


int YesOrNo() {

    const int code_word_len = 4;

    char CodeWord[code_word_len];
    scanf("%3s", CodeWord);

    while (!CheckInput(CodeWord, ClearBuf())) {
        SlowPrint("yes or no ;) ");
        scanf("%3s", CodeWord);
    }

    if (!strcmp(CodeWord, YES)) {
        return true;
    }

    return false;
}
