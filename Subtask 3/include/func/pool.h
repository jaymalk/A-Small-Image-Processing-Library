#include <vector>
#include <stdexcept>
#include <iostream>
#include "padding.h"

using namespace std;

#ifndef POOL_H
#define POOL_H
    vector<vector<int>> maxPool(vector<vector<int>> matrix, int filterSize = 2, int stride = 2 ){

        if(filterSize <= 0)
            throw runtime_error("Invalid filter size for pooling.");
        if(stride <= 0)
            throw runtime_error("Invalid stride size for pooling");
        if(stride > filterSize)
            cout << "\n\n -- Stride is greater than filter size, data was lost --\n\n";

        const int SIZE = matrix.size();
        int padSize = (SIZE-filterSize)%stride;

        if(SIZE<=0)
            throw runtime_error("Empty matrix. Can't pool.");

        if(padSize > 0){
            padSize = stride - padSize;
            matrix = pad(matrix, padSize);
        }

        int poolMatrixSize = 1 + (SIZE+padSize-filterSize)/stride;
        vector<vector<int>> pooledMatrix(poolMatrixSize);

        int row = 0;
        int iter = SIZE+padSize-filterSize;
        for(int i=0; i<=iter; i+=stride){
            pooledMatrix[row] = vector<int>(poolMatrixSize);

            int column = 0;
            for(int j=0; j<=iter; j+=stride){

                int max = matrix[i][j];

                for(int a=i; a<i+filterSize; a++)
                    for(int b=j; b<j+filterSize; b++)
                        if(matrix[a][b]>max)
                            max=matrix[a][b];

                pooledMatrix[row][column] = max;
                column++;
            }
            row++;
        }

        return pooledMatrix;
    }

    vector<vector<float>> maxPool(vector<vector<float>> matrix, int filterSize = 2, int stride = 2 ){

        if(filterSize <= 0)
            throw runtime_error("Invalid filter size for pooling.");
        if(stride <= 0)
            throw runtime_error("Invalid stride for pooling.");
        if(stride > filterSize)
            cout << "\n\n -- Stride is greater than filter size, data was lost --\n\n";

        const int SIZE = matrix.size();
        int padSize = (SIZE-filterSize)%stride;

        if(SIZE<=0)
            throw runtime_error("Empty matrix. Can't pool.");

        if(padSize > 0){
            padSize = stride - padSize;
            matrix = pad(matrix, padSize);
        }

        int poolMatrixSize = 1 + (SIZE+padSize-filterSize)/stride;
        vector<vector<float>> pooledMatrix(poolMatrixSize);

        int row = 0;
        int iter = SIZE+padSize-filterSize;
        for(int i=0; i<=iter; i+=stride){
            pooledMatrix[row] = vector<float>(poolMatrixSize);

            int column = 0;
            for(int j=0; j<=iter; j+=stride){

                float max = matrix[i][j];

                for(int a=i; a<i+filterSize; a++)
                    for(int b=j; b<j+filterSize; b++)
                        if(matrix[a][b]>max)
                            max=matrix[a][b];

                pooledMatrix[row][column] = max;
                column++;
            }
            row++;
        }

        return pooledMatrix;
    }

    vector<vector<float>> avgPool(vector<vector<int>> matrix, int filterSize = 2, int stride = 2 ){
        if(filterSize <= 0)
            throw "Invalid filter size for pooling.";
        if(stride <= 0)
            throw "Invalid stride for pooling.";
        if(stride > filterSize)
            cout << "\n\n -- Stride is greater than filter size, data was lost --\n\n";

        const int SIZE = matrix.size();
        int padSize = (SIZE-filterSize)%stride;

        if(SIZE<=0)
            throw runtime_error("Empty matrix. Can't pool.");

        if(padSize > 0){
            padSize = stride - padSize;
            matrix = pad(matrix, padSize);
        }

        int poolMatrixSize = 1 + (SIZE+padSize-filterSize)/stride;
        vector<vector<float>> pooledMatrix(poolMatrixSize);

        int row = 0;
        int iter = SIZE+padSize-filterSize;
        for(int i=0; i<=iter; i+=stride){
            pooledMatrix[row] = vector<float>(poolMatrixSize);

            int column = 0;
            for(int j=0; j<=iter; j+=stride){

                float sum = 0.0f;

                for(int a=i; a<i+filterSize; a++)
                    for(int b=j; b<j+filterSize; b++)
                        sum+=matrix[a][b];

                pooledMatrix[row][column] = sum/(filterSize*filterSize);
                column++;
            }
            row++;
        }

        return pooledMatrix;
    }

    vector<vector<float>> avgPool(vector<vector<float>> matrix, int filterSize = 2, int stride = 2 ){
        if(filterSize <= 0)
            throw runtime_error("Invalid filter size for pooling.");
        if(stride <= 0)
            throw runtime_error("Invalid stride for pooling.");
        if(stride > filterSize)
            cout << "\n\n -- Stride is greater than filter size, data was lost --\n\n";

        const int SIZE = matrix.size();
        int padSize = (SIZE-filterSize)%stride;

        if(SIZE<=0)
            throw runtime_error("Empty matrix. Can't pool.");

        if(padSize > 0){
            padSize = stride - padSize;
            matrix = pad(matrix, padSize);
        }

        int poolMatrixSize = 1 + (SIZE+padSize-filterSize)/stride;
        vector<vector<float>> pooledMatrix(poolMatrixSize);

        int row = 0;
        int iter = SIZE+padSize-filterSize;
        for(int i=0; i<=iter; i+=stride){
            pooledMatrix[row] = vector<float>(poolMatrixSize);

            int column = 0;
            for(int j=0; j<=iter; j+=stride){

                float sum = 0.0f;

                for(int a=i; a<i+filterSize; a++)
                    for(int b=j; b<j+filterSize; b++)
                        sum+=matrix[a][b];

                pooledMatrix[row][column] = sum/(filterSize*filterSize);
                column++;
            }
            row++;
        }
        return pooledMatrix;
    }
#endif
