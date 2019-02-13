#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#include "../padding.h"
#include "../../io/AIO.h"

using namespace std;

#ifndef CONVOLUTION_NOT_H
#define CONVOLUTION_NOT_H
    // FORMATTING FUNCTIONS
    /* Change 2D square matrix to 1D matrix(row major) */
    vector<float> changeTo1D(vector<vector<float>> kernel) {
            vector<float> kernel1D(kernel[0].begin(), kernel[0].end());
            for(int i=1; i<kernel.size(); i++)
                    kernel1D.insert(kernel1D.end(), kernel[i].begin(), kernel[i].end());
            return kernel1D;
    }

    /* Change 1D matrix (in row major form) (assuming size to be perfect square) to 2D square matrix*/
    vector<vector<float>> changeToSqaure2D(vector<float> col) {
            vector<vector<float>> matrix;
            int size = (int)(sqrt(col.size()));
            for(int i=0; i<size; i++)
                    matrix.push_back(vector<float>(col.begin()+i*size, col.begin()+(i+1)*size));
            return matrix;
    }

    // DIRECT CONVOLUTION

    vector<vector<float>> invertKernel(vector<vector<float>>& kernel) {
        vector<float> kernel1D = changeTo1D(kernel);
        reverse(kernel1D.begin(), kernel1D.end());
        kernel = changeToSqaure2D(kernel1D);
        return kernel;
    }

    vector<vector<float>> directConvolution(vector<vector<float>> kernel, vector<vector<float>> matrix, bool convolution, bool padding=false) {
        if(padding)
            matrix = pad(matrix, kernel.size()-1);
        if(convolution)
            kernel = invertKernel(kernel);

        int kernelSize = kernel.size(), matrixSize = matrix.size();

        vector<vector<float>> conv{};

        for(int i=0; i<matrixSize-kernelSize+1; i++)
            conv.push_back(vector<float>{});

        for(int i=0; i<matrixSize-kernelSize+1; i++)
            for(int j=0; j<matrixSize-kernelSize+1; j++) {
                float val = 0.0;
                for(int k=0; k<kernelSize; k++)
                    for(int l=0; l<kernelSize; l++)
                        val += matrix[i+k][j+l]*kernel[k][l];
                conv[i].push_back(val);
            }

        return conv;
    }

    // CONVOLUTION BY MULTIPLICATION

    /* Convert the matrix to toeplitz matrix, by using the order of square kernel
    The conversion of 2D mapping is converted to 1D considering row major*/
    vector<vector<float>> convertToToeplitzMatrix(vector<vector<float>> matrix, int kernel_size) {
            vector<vector<float>> toeplitz{};
            for(int i=0; i<matrix.size()-kernel_size+1; i++)
                    for(int j=0; j<matrix.size()-kernel_size+1; j++) {
                            vector<float> row{};
                            for(int k=0; k<kernel_size; k++)
                                    for(int l=0; l<kernel_size; l++)
                                            row.push_back(matrix[i+k][j+l]);
                            toeplitz.push_back(row);
                    }
            return toeplitz;
    }

    /* Multiply the toeplits form and kernel, to get 1D convolution*/
    vector<float> getConvolutionByMultiplication(vector<vector<float>> toeplitz, vector<float> kernel) {
            vector<float> product;
            for(int i=0; i<toeplitz.size(); i++) {
                    float val=0.0;
                    for(int j=0; j<kernel.size(); j++)
                            val += (toeplitz[i][j]*kernel[j]);
                    product.push_back(val);
            }
            return product;
    }

    /* The encapsulating layer for complete function
    First two parameters are kernel and matrix, resp.
    Third for selection between convolution (true) and cross-correlation (false)
    To include padding additional argument 'boolean' shall surmise*/
    vector<vector<float>> convolutionByMultiplication(vector<vector<float>> kernel, vector<vector<float>> matrix, bool convolution, bool padding=false) {
            if(padding)
                    matrix = pad(matrix, kernel.size()-1);
            vector<float> kernel1D = changeTo1D(kernel);
            if(convolution)
                reverse(kernel1D.begin(), kernel1D.end()); // For convolution instead of cross-correlation
            vector<vector<float>> toeplitz = convertToToeplitzMatrix(matrix, kernel.size());
            vector<float> conv1d = getConvolutionByMultiplication(toeplitz, kernel1D);
            return changeToSqaure2D(conv1d);
    }
#endif
