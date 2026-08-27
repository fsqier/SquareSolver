/*!
\file
\brief Заголовочный файл с решением квадратки

*/

#ifndef SOLVER_H
#define SOLVER_H

/// Набор возможных значений переменной, указывающей на количество корней
enum cnt_roots_t {
    INF_ROOTS = -1,
    NO_ROOTS  = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2
};

/*!
Решает квадратное уравнение любого вида
\return Количество корней
*/
int    SquareSolver(double a, double b, double c, double* x1, double* x2);
/*!
Решает уравнение, где a != 0
*/
int    SquareEq    (double a, double b, double c, double* x1, double* x2);
/*!
Решает уравнение, где a == 0
*/
int    LineEq      (double b, double c, double* x1);
/*!
Сравнивает число типа double с нулем
*/
int    IsZero      (double num);

///Погрешность с которой число типа double сравнивается с 0
const double eps = 1e-2;

///Макрос для вычисления дискриминанта
#define DISCR(a, b, c) ((b) * (b) - 4 * (a)*(c))

#endif
