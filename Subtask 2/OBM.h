//g++ test.cpp -I /include/ -L/lib/ -lopenblas -lpthread
// #include <cblas.h>
#include <stdio.h>
#include <iostream>

#ifndef OPEN_BLAS
#define OPEN_BLAS

extern "C"{
  int dgemm_(char *, char *, int *, int *, int *, double *, double *, int *,
              double *, int *, double *, double *, int *);
}

/* Assuming row major order of matrices.

    This function is used to call open_blas multiplication. I takes the paramters given and
    puts the result of multiplication in C.

    To be used in open_blas_measure.cpp
*/
void call_open_blas(double *A, int rowA, double *B, int colB, int commonSide, double *C) {
    char t = 'N';
    double alpha =1.0;
    double beta = 0.0;
    dgemm_(&t, &t, &rowA, &colB, &commonSide, &alpha, A, &rowA, B, &commonSide, &beta, C, &rowA);
}

// int main()
// {
//     int i=0;
//     double A[6] = {1.0,2.0,1.0,-3.0,4.0,-1.0};
//     double B[6] = {1.0,2.0,1.0,-3.0,4.0,-1.0};
//     double C[9] = {.5,.5,.5,.5,.5,.5,.5,.5,.5};
//     char t = 'N';
//     int rowA = 3;
//     int commonSide = 2;
//     int colB = 3;
//     double alpha =1.0;
//     double beta = 0.0;
//
//     dgemm_(&t, &t, &rowA, &colB, &commonSide, &alpha, A, &rowA, B, &commonSide, &beta, C, &rowA);
//
//     for(i=0; i<9; i++)
//         printf("%lf ", C[i]);
//     printf("\n");
// }

#endif
