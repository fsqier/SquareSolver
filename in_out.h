/*!
@file in_out.h
@brief Файл отвечающий за вывод и ввод в консоль всего, что связано с квадраткой
*/

#ifndef IN_OUT_H
#define IN_OUT_H


/*!
@brief Выводит строку постепенно

@param text Выводимый текст
*/

void SlowPrint (const char* text);
/*!
@brief Выводит количество решений уравнения и, при необходимости, корни

@param CntRoots Количество корней уравнения
@param x1 Первый корень
@param x2 Второй корень
*/

void OutputSolves (int CntRoots, double x1, double x2);

/*!
@brief Спрашивает у пользователя, нужно ли ему еще раз решить квадратку

@return Если нужно решить еще раз -- true, иначе -- false
*/

int NeedContinue ();

/*!
@brief Проверяет ввод кодового слова для продолжения работы с программой\

@param CodeWord введенный текст
@param CntWrongSymb количество "мусорных" символов, оставшихся в буфере

@return Если введено yes или no -- true, иначе -- false
*/

int CheckInput (char* CodeWord, int CntWrongSymb);\

/*!
@brief Проверяет ввод коэффициентов

@param a коэффициент a
@param b коэффициент b
@param c коэффициент с

@return Если коэффициенты введены верно -- true, иначе -- false
*/

int InputCoef (double* a, double* b, double* c);

/*!
@brief Очищает буффер ввода

@ return Количество "мусорных" символов, оставшихся в буффере
*/

int ClearBuf ();

/*!
@brief Спрашивает у пользователя, нужно ли провести тестирование программы

@return Если нужно тестирование -- true, иначе -- false
*/

int NeedTest ();

/*!
@brief Определяет, введено ли слово yes(программа продолжит выполнение) или no

@return Если введено yes -- true, иначе -- false
*/

int YesOrNo ();

#define YES "yes"
#define NO "no"
#define ALL_CORRECT_COEFS 3

#endif
