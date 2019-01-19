/*
   Multiplying a n*m Matrix with m*1 kernel1D using threading
 */

#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <vector>
#include "../Subtask 1/IO.h"
#include "../Subtask 1/NIO.h"

using namespace std;

vector<vector<float>> matrix;
vector<float> vctor;
vector<float> prod;

void *newmult(void *pass) {
    int* i = (int *)pass;

    int a = *(i);
    int b = *(i+1);

    for(int k = a; k<b; k++) {
        for(int j=0; j<vctor.size(); j++)
            prod[k] += (matrix[k][j] * vctor[j]);
    }

    return NULL;
}

void multiplyThreaded(int no_threads=6) {

        pthread_t p[no_threads];

        int ms = matrix.size(), n = no_threads;

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

int main(int argc, char** argv) {
        int n = stoi(argv[1]);
        int m = stoi(argv[2]);

        matrix = inputMatrix("f/size_"+to_string(n*m)+".txt", n);

        vctor = inputVector("f/size_"+to_string(m)+".txt");

        prod = vector<float>(n, 0);

        if(argc == 4)
            multiplyThreaded(stoi(argv[3]));
        else
            multiplyThreaded();

        printVector(prod);

        return 0;
}
