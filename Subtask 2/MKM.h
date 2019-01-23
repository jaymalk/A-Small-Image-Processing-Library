//g++ -o exe mkl.cpp -L${MKLROOT}/lib/intel64 -Wl,--no-as-needed -lmkl_intel_ilp64 -lmkl_gnu_thread -lmkl_core -lgomp -lpthread -lm -ldl

#include <stdio.h>
#include <stdlib.h>
#include "mkl.h"

#ifndef MKM_H
#define MKM_H

void call_mkl(double *A, int rowA, double *B, int colB, int commonSide, double *C) {
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
    rowA, colB, commonSide, 1.0, A, commonSide, B, colB, 0.0, C, colB);
}

#endif
