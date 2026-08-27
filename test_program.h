#ifndef TEST_PROGRAM_H
#define TEST_PROGRAM_H

struct TestValRef {
    double a, b, c;
    int CntRoots;
    double x1, x2;
};


void   RunAllTests ();
void   CntTest     (double a, double b, double c, int CntRoot,
                    double x1, double x2, int* cnt_all_test, int* cnt_correct_test);
int    CorrectTest (double a, double b, double c, int CntRoot, double x1, double x2);
int    RunOneTest  (TestValRef test);
int    CorrectAns  (TestValRef test, int CntRoots, double x1, double x2);

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

#endif
