/*
   Converting to toeplitz tmatrix using threading
 */

#include <iostream>
#include <stdlib.h>
#include <pthread.h>

using namespace std;

#ifndef TC_H
#define TC_H

double * matrix;       // Square matrix to be converted
double * tmatrix;         // Converted Matrix
int mSize, kSize, tRow, tCol;

void *convert(void *pass) {
    int* i = (int *)pass;

    int a = *(i);
    int b = *(i+1);
    int ii, jj;

    int l = mSize-kSize+1;
    int m = kSize;

    for(int r=a; r<b; r++) {
        ii = (int)(r/l);
        jj = r%l;
        for(int k=0; k<m; k++)
                for(int p=0; p<m; p++) {
                        tmatrix[r*tCol + k*m + p] = matrix[(ii+k)*mSize+jj+p];
                    }
    }
    return NULL;
}

void convertThreaded(int no_threads=2) {
    pthread_t p[no_threads];

    int n = no_threads, nr = tRow;

    int a[n][2], s = 0, e = nr/n, add = nr/n;
    for(int i=0; i<n; i++) {
        a[i][0] = s;
        a[i][1] = e;
        s = e;
        e += add;
    }
    a[n-1][1] = nr;

    for(int i=0; i<n; i++)
        pthread_create(p+i, NULL, convert, (void *)a[i]);

    for(pthread_t pt:p)
        pthread_join(pt, NULL);

}

double * convertToToeplitzForm(double * A, int sizeA, int sizeB) {
    matrix = A;
    mSize = sizeA;
    kSize = sizeB;
    tRow = (mSize-kSize+1)*(mSize-kSize+1);
    tCol = kSize*kSize;
    tmatrix = (double *)malloc(sizeof(double)*(tRow)*(tCol));
    convertThreaded();
    return tmatrix;
}

#endif
