#include "in_out.h"
#include "solver.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//вывод решений
 void OutputSolves(int CntRoots, double x1, double x2) {

    printf("Количество корней: ");

    switch(CntRoots) {
        case INF_ROOTS:
            printf("Бесконечно много\n");
            break;
        case NO_ROOTS:
            printf("0\n");
            break;
        case ONE_ROOT:
            printf("1\nx: %lg\n", x1);
            break;
        case TWO_ROOTS:
            printf("2\nx1: %lg, x2: %lg\n", x1, x2);
            break;
        default:
            printf("Корней почему-то больше двух и меньше INF\n");
            break;
    }
 }

//проверяет, нужно ли решить ещё уравнение
int NeedContinue() {

    printf("Продолжить?(yes/no) ");
    return YesOrNo();
}

//проверяет, ввод кодового слова
 int CheckInput(char* CodeWord, int WrongSymb) {

    if ((!strcmp(CodeWord, YES) || !strcmp(CodeWord, NO)) && !WrongSymb) {
        return true;
    }

    return false;
 }

//ввод коэффициентов и проверка корректности
int InputCoef(double* a, double* b, double* c) {

    printf("Введите коэффициенты:");
    int correct_coefs = scanf("%lg %lg %lg", a, b, c);
    int cnt_wrong_symb = ClearBuf();

    if (correct_coefs != ALL_CORRECT_COEFS || cnt_wrong_symb > 0) {
        return false;
    }

    printf("a: %lg, b: %lg, c: %lg\n", *a, *b, *c);

    return true;
}

//чистка буффера ввода и подсчёт лишних символов
//дает знать, есть ли лишние символы
int ClearBuf() {

    int cnt_wrong_symb = 0;
    int ch = getchar();
    while (ch != '\n') {
        if (ch != ' ') {
            ++cnt_wrong_symb;
        }
        ch = getchar();
    }

    return (cnt_wrong_symb > 0);
 }

int NeedTest() {

    printf("Нужно тестирование?(yes/no) ");
    return YesOrNo();
}

//ввели yes или no
int YesOrNo() {

    const int code_word_len = 4;

    char CodeWord[code_word_len];
    scanf("%3s", CodeWord);

    while (!CheckInput(CodeWord, ClearBuf())) {
        printf("yes or no ;) ");
        scanf("%3s", CodeWord);
    }

    if (!strcmp(CodeWord, YES)) {
        return true;
    }

    return false;
}
