/*!
\file
\brief Заголовочный файл отвечающий за тестирование программы

*/

#ifndef TEST_PROGRAM_H
#define TEST_PROGRAM_H

/*!
Cтруктура для тестирования программы.
Хранит референсные значения квадратного уравнения
*/

struct TestValRef {
    double a, b, c;
    int CntRoots;
    double x1, x2;
};

/*!
Тестирует решение квадратного уравнения.
Тесты берет из файла test.txt
*/
void   RunAllTests ();
/*!
Считает пройденное количество тестов
\param cnt_all_test  Общее количество тестов
\param cnt_correct_test Количество успешно пройденных тестов
*/
void   CntTest     (double a, double b, double c, int CntRoot,
                    double x1, double x2, int* cnt_all_test, int* cnt_correct_test);
/*!
Создает тест и вызывает RunOneTest(...)
*/
int    CorrectTest (double a, double b, double c, int CntRoot, double x1, double x2);
/*!
Решает квадратку по коэффициентам, выводит результаты теста
*/
int    RunOneTest  (TestValRef test);
/*!
Сравнивает получившиеся значения с референсными
*/
int    CorrectAns  (TestValRef test, int CntRoots, double x1, double x2);

///Макрос для нахождения максимума из двух чисел
#define MAX(x, y) ((x) > (y) ? (x) : (y))
///Макрос для нахождения минимума из двух чисел
#define MIN(x, y) ((x) < (y) ? (x) : (y))

#endif
