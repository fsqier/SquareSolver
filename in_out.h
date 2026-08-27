#ifndef IN_OUT_H
#define IN_OUT_H

void   OutputSolves(int CntRoots, double x1, double x2);
int    NeedContinue();
int    CheckInput  (char* CodeWord, int CntWrongSymb);
int    InputCoef   (double* a, double* b, double* c);
int    ClearBuf    ();
int    NeedTest    ();
int    YesOrNo     ();

#define YES "yes"
#define NO "no"
#define ALL_CORRECT_COEFS 3

#endif
