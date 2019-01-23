#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

/* File for converting vectors to Arrays(Linear) */

#ifndef V2A_H
#define V2A_H

    double * convertToArray(vector<vector<float>> matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        double *array = (double *)malloc(sizeof(double)*rows*cols);
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                array[i*cols+j] = matrix[i][j];
        return array;
    }

    double * convertToArray(vector<float> vctor) {
        int rows = 1;
        int cols = vctor.size();
        double *array = (double *)malloc(sizeof(double)*rows*cols);
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                array[i*cols+j] = vctor[j];
        return array;
    }

#endif
