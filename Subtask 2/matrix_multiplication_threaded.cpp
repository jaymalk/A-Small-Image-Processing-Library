/*
   Multiplying a n*n Matrix with n*1 kernel1D using threading
 */

#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <vector>
#include "../Subtask 1/IO.h"
#include "../Subtask 1/NIO.h"

using namespace std;


struct arg {
        vector<float> row;
        vector<float> kernel1D;
        float val;

        arg(vector<float> row, vector<float> kernel1D) {
                this->row = row;
                this->kernel1D = kernel1D;
                this->val = 0.0f;
        }
};

void *mult(void *pass) {
        arg* row = (arg*)pass;

        for(int i=0; i<(row->row.size()); i++) {
                row->val += ((row->row[i]) * (row->kernel1D[i]));
        }

        return NULL;
}

vector<float> multiply(vector<vector<float> > matrixToep, vector<float> kernel1D) {

        arg *row[matrixToep.size()];
        for(int i=0; i<matrixToep.size(); i++)
                row[i] = new arg(matrixToep[i], kernel1D);

        pthread_t p[matrixToep.size()];
        for(int i=0; i<matrixToep.size(); i++)
                pthread_create(p+i, NULL, mult, (void *)(row[i]));

        for(int i=0; i<matrixToep.size(); i++)
                pthread_join(p[i], NULL);

        vector<float> prod{};
        for(int i=0; i<matrixToep.size(); i++)
                prod.push_back(row[i]->val);
        return prod;
}

int main(int argc, char** argv) {

        vector<vector<float>> matrixToep = inputSquareMatrix(argv[1]);
        vector<float> kernel1D = inputVector(argv[2]);
        if(matrixToep.size() != kernel1D.size()) {
            cout << "Error: Files are wrong.";
            exit(0);
        }
        printVector(multiply(matrixToep, kernel1D));

        return 0;
}
