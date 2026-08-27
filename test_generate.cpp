#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

double RandDouble         ();
void   GenerateTest       ();
void   GeneratePopularTest(FILE* fp);
void   GenerateSpecialTest(FILE* fp);
void   PrintInFile        (FILE* fp);
void   PrintInFile        (FILE* fp, double a, double b, double c,
                                int CntRoots, double x1, double x2)

int main() {

    GenerateTest();

    return 0;
}

void GenerateTest() {

    FILE* fp = fopen("tests.txt", "w");
    assert(fp != NULL);

    srand(time(NULL));

    GeneratePopularTest(fp);

    GenerateSpecialTest(fp);

    fclose(fp);
}


void GeneratePopularTest(FILE* fp) {

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    //два корня
    for (int i = 0; i < 50; ++i) {
        x1 = RandDouble();
        x2 = RandDouble();
        a = RandDouble();
        b = (x1 + x2) * (-a);
        c = (x1 * x2) * a; //по теореме виета
        PrintInFile(fp, a, b, c, 2, x1, x2);
    }
}

void GenerateSpecialTest(FILE* fp) {

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    //все коэф нули
    PrintInFile(fp, 0.0, 0.0, 0.0, -1, 0.0, 0.0);

    //c != 0, a == 0, b == 0
    PrintInFile(fp, 0.0, 0.0, RandDouble(), 0, 0.0, 0.0);

    //b != 0, c == 0, a == 0
    PrintInFile(fp, 0.0, RandDouble(), 0.0, 1, 0.0, 0.0);

    //a == 0, c != 0, b != 0
    c = RandDouble();
    b = RandDouble();
    PrintInFile(fp, 0.0, b, c, 1, -c/b, 0.0);

    //a != 0, c == 0, b == 0
    PrintInFile(fp, RandDouble(), 0.0, 0.0, 1, 0.0, 0.0);

    //b == 0, c != 0, a != 0
    a = RandDouble();
    c = RandDouble();
    if (a * c <= 0) {
        PrintInFile(fp, a, 0.0, c, 1, sqrt(-c/a), 0.0);
    } else {
        PrintInFile(fp, a, 0.0, c, 0, 0.0, 0.0);
    }

    //c == 0, a != 0, b != 0
    a = RandDouble();
    b = RandDouble();
    PrintInFile(fp, a, b, 0.0, 2, 0.0, -b/a);
}


void PrintInFile (FILE* fp, double a, double b, double c, int CntRoots, double x1, double x2) {

    fprintf(fp, "%lg %lg %lg %d %lg %lg\n", a, b, c, CntRoots, x1, x2);
}


double RandDouble () {

    const double min_coef = -10.0, len_range = 20.0;

    double num = (double)rand() / RAND_MAX * len_range + min_coef;
    assert(isfinite(num));

    return num;
}
