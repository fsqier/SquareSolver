/*!
\file
\brief Заголовочный файл отвечающий за вывод и правильный ввод

*/

#ifndef IN_OUT_H
#define IN_OUT_H


const int code_word_len = 4;

/*!
Выводит количество решений и корни(по необходимости)
*/
void   OutputSolves(int CntRoots, double x1, double x2);
/*!
Спрашивает у пользователя, нужно ли ему еще раз решить квадратку
*/
int    NeedContinue();
/*!
Проверяет ввод кодового слова для продолжения работы с программой
*/
int    CheckInput  (char* CodeWord, int CntWrongSymb);
/*!
Проверяет ввод коэффициентов
*/
int    InputCoef   (double* a, double* b, double* c);
/*!
Очищает буффер ввода
\return Количество "мусорных" символов, оставшихся в буффере
*/
int    ClearBuf    ();
/*!
Спрашивает у пользователя, нужно ли провести тестирование программы
*/
int    NeedTest    ();
/*!
Определяет, введено ли слово yes(программа продолжит выполнение) или no
*/
int    YesOrNo     ();

#define YES "yes"
#define NO "no"
#define ALL_CORRECT_COEFS 3

#endif
