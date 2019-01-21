//g++ test.cpp -I /include/ -L/lib/ -lopenblas -lpthread
// #include <cblas.h>
#include <stdio.h>

extern "C"{
  int dgemm_(char *, char *, int *, int *, int *, double *, double *, int *,
              double *, int *, double *, double *, int *);
}


int main()
{
    int i=0;
  double A[6] = {1.0,2.0,1.0,-3.0,4.0,-1.0};         
  double B[6] = {1.0,2.0,1.0,-3.0,4.0,-1.0};  
  double C[9] = {.5,.5,.5,.5,.5,.5,.5,.5,.5};
  char t = 'N';
  int rowA = 3;
  int commonSide = 2;
  int colB = 3;
  double alpha =1.0;
  double beta = 0.0;

  dgemm_(&t, &t, &rowA, &colB, &commonSide, &alpha, A, &rowA, B, &commonSide, &beta, C, &rowA);

  for(i=0; i<9; i++)
    printf("%lf ", C[i]);
  printf("\n");
}