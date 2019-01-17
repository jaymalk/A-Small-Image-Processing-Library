#include <vector>
#include <cmath>
#include <stdexcept>
//#include <iostream>

using namespace std;

#ifndef ACTIVATION_H
#define ACTIVATION_H

    vector<float> sigmoid(vector<float> arr){
        const int SIZE = arr.size();

        if(SIZE<=0)
            throw runtime_error("Empty array for sigmoid.");

        for(int i=0; i<SIZE; i++){
            if(arr[i] < -50)
                arr[i] = 0;
            else if(arr[i] > 50)
                arr[i] = 1;
            else    
                arr[i] = 1.0/(1+exp(-1*arr[i]));
        }
        return arr;
    }


    vector<float> softmax(vector<float> arr){
        const int SIZE = arr.size();
        float sum=0.0f;

        if(SIZE<=0)
            throw runtime_error("Empty array for softmax.");

        for(int i=0; i<SIZE; i++){
            arr[i] = exp(arr[i]);
            sum += arr[i];
        }

        for(int i=0;i <SIZE;i ++)
            arr[i] /= sum;

        return arr;
    }

    vector<vector<int>> relu(vector<vector<int>> matrix){
        if(matrix.size()<=0)
            throw runtime_error("Empty matrix for relu.");

        for(int i=0; i<matrix.size(); i++)
            for(int j=0; j<matrix[0].size(); j++)
                matrix[i][j] = max(0, matrix[i][j]);

        return matrix;
    }

    vector<vector<float>> relu(vector<vector<float>> matrix){
        if(matrix.size()<=0)
            throw runtime_error("Empty matrix for relu.");

        for(int i=0; i<matrix.size(); i++)
            for(int j=0; j<matrix[0].size(); j++)
                matrix[i][j] = max(0.0f, matrix[i][j]);

        return matrix;
    }

    vector<vector<float>> tanh(vector<vector<int>> matrix){
        const int SIZE = matrix.size();

        if(SIZE<=0)
            throw runtime_error("Empty matrix for tanh.");

        vector<vector<float>> tanhMatrix(SIZE);              // new matrix due to different data-type of input and output

        for(int i=0; i<SIZE; i++){
            tanhMatrix[i] = vector<float>(matrix[0].size());
            for(int j=0; j<matrix[0].size(); j++)
            tanhMatrix[i][j] = 2.0/(1+exp(-2.0*matrix[i][j])) - 1;
        }

        return tanhMatrix;
    }


    vector<vector<float>> tanh(vector<vector<float>> matrix){
        if(matrix.size()<=0)
            throw runtime_error("Empty matrix for tanh.");

        for(int i=0; i< matrix.size(); i++)
            for(int j=0; j<matrix[0].size(); j++)
                matrix[i][j] = 2.0/(1+exp(-2.0*matrix[i][j])) - 1;

        return matrix;
    }

#endif
