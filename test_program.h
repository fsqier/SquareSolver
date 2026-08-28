/*!
@file test_program.h
@brief Файл, тестирующий квадратку
*/

#ifndef TEST_PROGRAM_H
#define TEST_PROGRAM_H

struct TestValRef {
    double a, b, c;
    int CntRoots;
    double x1, x2;
};


/*!
@brief Запускает тестирование из файла
*/

void   RunAllTests ();

/*!
@brief Считает количество тестов

@param a Коэффициент a
@param b Коэффициент b
@param c Коэффициент с
@param CntRoot Референсное значения количества корней
@param x1 Референсное значение первого корня
@param x2 Референсное значение второго корня
@param cnt_all_test Указатель на общее количество тестов
@param cnt_correct_test Указатель на успешное количество тестов
*/

void   CntTest     (double a, double b, double c, int CntRoot,
                    double x1, double x2, int* cnt_all_test, int* cnt_correct_test);

/*!
@brief Создает объект типа TestValRef

@param a Коэффициент a
@param b Коэффициент b
@param c Коэффициент с
@param CntRoot Референсное значения количества корней
@param x1 Референсное значение первого корня
@param x2 Референсное значение второго корня

@return Если тест пройден успешно -- true, иначе -- false
*/

int    CorrectTest (double a, double b, double c, int CntRoot, double x1, double x2);

/*!
@brief Запускает тест и выводит получившийся результат

@param test Объект, где хранятся коэффициенты и референсные значения для сравнения с ответом

@return Если тест пройден успешно -- true, иначе -- false
*/

int    RunOneTest  (TestValRef test);

/*!
@brief Проверяет, успешно ли пройден тест

@param test Объект с референсными значениями
@param CntRoots Получившееся количество корней
@param x1 Получившийся первый корень
@param x2 Получившийся второй корень

@return Если тест пройден успешно -- true, иначе -- false
*/

int    CorrectAns  (TestValRef test, int CntRoots, double x1, double x2);

#endif
