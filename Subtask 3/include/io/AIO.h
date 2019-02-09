#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/* Functions for working I/O with Arrays(Linear) */

#ifndef V2A_H
#define V2A_H

    /* Converting a vector of vectors into a 1D array.
        Used for matrix_multiplication via threading.
        */
    double * convertToArray(vector<vector<float>> matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        double *array = (double *)malloc(sizeof(double)*rows*cols);
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                array[i*cols+j] = matrix[i][j];
        return array;
    }

    /* Converting a vector into a 1D array.
        Used for matrix_multiplication via threading.
        */
    double * convertToArray(vector<float> vctor) {
        int rows = 1;
        int cols = vctor.size();
        double *array = (double *)malloc(sizeof(double)*rows*cols);
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                array[i*cols+j] = vctor[j];
        return array;
    }

    /* Writing a (2D matrix) 1D array on a file.
        Column major order.
        */
    void write2DArray(double * arr, int numRow, int numCol, ostream& out =cout) {
        for(int i=0; i<numCol; i++)
            for(int j=0; j<numRow; j++) {
                out << setprecision(14) << arr[i+j*numRow] << "\n";
            }
    }

    /* Writing a (2D square matrix) 1D array on a file.
        Column major order.
        */
    void writeSquareArray(double *arr, int size, ostream& out=cout) {
        write2DArray(arr, size, size, out);
    }

    /* Writing a (vector) 1D array on a file.
        */
    void write1DArray(double *arr, int size, ostream& out = cout) {
        write2DArray(arr, size, 1, out);
    }

    /* Printing a formatted version of matrix */
    void print2DArray(double * arr, int numRow, int numCol) {
        for(int i=0; i<numRow; i++) {
            for(int j=0; j<numCol; j++)
                cout << setw(15) << setprecision(10) << arr[i*numCol+j] << " ";
            cout << "\n";
        }
    }

    /* Printing a formatted version of a square matrix */
    void printSquareArray(double *arr, int size) {
        print2DArray(arr, size, size);
    }

    /* Printing a formatted version of vector */
    void print1DArray(double * arr, int size) {
        for(int i=0; i<size; i++)
                cout << setw(10) << setprecision(5) << arr[i] << "\n";
    }

#endif
