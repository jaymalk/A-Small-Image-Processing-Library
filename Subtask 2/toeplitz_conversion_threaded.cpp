/*
   Converting to toeplitz form using threading
 */

#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <vector>
#include "../Subtask 1/IO.h"
#include "../Subtask 1/NIO.h"

using namespace std;

vector<vector<float>> matrix;       // Square matrix to be converted
vector<vector<float>> kernel;       // Square kernel used for conversion
vector<vector<float>> form;         // Converted Matrix

void *convert(void *pass) {
    int* i = (int *)pass;

    int a = *(i);
    int b = *(i+1);
    int ii, jj;

    int l = matrix.size()-kernel.size()+1;
    int m = kernel.size();

    for(int r=a; r<b; r++) {
        ii = (int)(r/l);
        jj = r%l;
        for(int k=0; k<m; k++)
                for(int p=0; p<m; p++)
                        form[r].push_back(matrix[ii+k][jj+p]);
    }
    return NULL;
}

void convertThreaded(int no_threads=2) {
    pthread_t p[no_threads];

    int n = no_threads, nr = form.size();

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

int main(int argc, char** argv) {
    int n = stoi(argv[1]);
    int m = stoi(argv[2]);

    matrix = inputSquareMatrix("f/size_"+to_string(n*n)+".txt");

    kernel = inputSquareMatrix("f/size_"+to_string(m*m)+".txt");

    form = vector<vector<float>>((n-m+1)*(n-m+1), vector<float>{});


    if(argc == 4)
        convertThreaded(stoi(argv[3]));
    else
        convertThreaded();

    printMatrix(form);
}
