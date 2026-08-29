/*!
@file graphics.h
@brief Файл отвечающий за рисование графиков
*/

#ifndef GRAPHICS_H
#define GRAPHICS_H


const double SIZE_X = 600.0;
const double SIZE_Y = 600.0;
const double CENTER_X = SIZE_X / 2.0;
const double CENTER_Y = SIZE_Y / 2.0;
const double SCALE = 20.0;


/*!
@brief Настраивает окно
*/

void SetWindow ();

/*!
@brief Рисует оси координат
*/

void DrawAxes ();

/*!
@brief Рисует график функции по уравнению

@param a коэффициент a
@param b коэффициент b
@param c коэффициент c
*/

void DrawParabola (double a, double b, double c);

/*!
@brief Переводит координаты математические в "оконные"

@param num координата
@param size размер по которому идет пересчёт

@return координату получившуюся
*/

double OnWindow (double num, double size);

/*!
@brief Спрашивает у пользователя числа для цвета графика

@param a коэффициент a
@param b коэффициент b
@param c коэффициент с

*/

void ChooseColor (double a, double b, double c);


#endif
