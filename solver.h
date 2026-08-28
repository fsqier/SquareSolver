/*!
@file solver.h
@brief Файл с функциями решающими квадратку
*/

#ifndef SOLVER_H
#define SOLVER_H


/*!
@brief Количество корней, которое может быть у квадратного уравнения
*/

enum cnt_roots_t {
    INF_ROOTS = -1,
    NO_ROOTS  = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2
};

/*!
@brief Решает квадратное уравнение любого вида

@param a Коэффициент a
@param b Коэффициент b
@param c Коэффициент с
@param x1 Указатель на первый корень
@param x2 Указатель на второй корень

@return Количество корней

@note Изменяет значения x1 и x2
*/

int    SquareSolver(double a, double b, double c, double* x1, double* x2);

/*!
@brief Решает квадратное уравнение, где a != 0

@param a Коэффициент a
@param b Коэффициент b
@param c Коэффициент с
@param x1 Указатель на первый корень
@param x2 Указатель на второй корень

@return Количество корней

@note Изменяет значения x1 и x2
*/

int    SquareEq    (double a, double b, double c, double* x1, double* x2);

/*!
@brief Решает квадратное уравнение, где a == 0

@param b Коэффициент b
@param c Коэффициент с
@param x1 Указатель на первый корень

@return Количество корней

@note Изменяет значения x1
*/

int    LineEq      (double b, double c, double* x1);

/*!
@brief Сравнивает число типа double с 0

@param num Число типа double :(

@return Если число равно 0 с погрешностью eps -- true, иначе -- false
*/

int    IsZero      (double num);

/*!
@brief Считает дискриминант

@param a Коэффициент a
@param b Коэффициент b
@param c Коэффициент с

@return Дискриминант
*/

#define DISCR(a, b, c) ((b) * (b) - 4 * (a)*(c))

#endif
