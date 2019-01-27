/*
   Threaded multiplication of a mtrx (m*n) with a vector (n*1), giving anothre vector
 */

#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <cmath>
#include <unistd.h>

using namespace std;

double * mtrx;
double * vctor;
double * prod;
int vc_len;


/*
    The threaded function to be called by a pthread.
    Accumulates the value in position.
*/
void *newmult(void *pass) {
    int* i = (int *)pass;

    int a = *(i);
    int b = *(i+1);

    for(int k = a; k<b; k++) {
        prod[k] = 0;
        for(int j=0; j<vc_len; j++)
            prod[k] += (mtrx[k*vc_len+j] * vctor[j]);
    }

    return NULL;
}

/*
    The multiplication function, prepares and creates thread
*/
void multiplyThreaded(int rowA, int no_threads=6) {

        pthread_t p[no_threads];

        int ms = rowA, n = no_threads;

        int a[n][2], s = 0, e = ms/n, add = ms/n;
        for(int i=0; i<n; i++) {
            a[i][0] = s;
            a[i][1] = e;
            s = e;
            e += add;
        }
        a[n-1][1] = ms;

        for(int i=0; i<n; i++)
            pthread_create(p+i, NULL, newmult, (void *)a[i]);

        for(pthread_t pt:p)
            pthread_join(pt, NULL);

}

/*
    To call multiplication from outside. Intakes pointers to values
    and puts them for global multiplication.
*/
double * call_multiplication(double *A, int rowA, double *B, int rowB, double *C) {
    mtrx = A;
    vctor = B;
    prod = C;
    vc_len = rowB;
    int no_threads = 1+min((int)(sysconf(_SC_NPROCESSORS_ONLN) - 2), (int)(pow(rowA, .35) - 1));
    multiplyThreaded(rowA, no_threads);
    return prod;
}
