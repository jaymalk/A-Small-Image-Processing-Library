#include <vector>
using namespace std;

#ifndef CONVOLUTION_H
#define CONVOLUTION_H
    vector<float> changeTo1D(vector<vector<float>> kernel);
    vector<vector<float>> changeToSqaure2D(vector<float> col);

    vector<vector<float>> invertKernel(vector<vector<float>>& kernel);
    vector<vector<float>> mapping(vector<vector<float>> kernel, vector<vector<float>> matrix, bool convolution, bool padding=false);

    vector<vector<float>> convertToToeplitzMatrix(vector<vector<float>> matrix, int kernel_size);
    vector<float> getConvolutionByMultiplication(vector<vector<float>> toeplitz, vector<float> kernel);
    vector<vector<float>> convolutionByMultiplication(vector<vector<float>> kernel, vector<vector<float>> matrix, bool convolution, bool padding=false);
#endif
