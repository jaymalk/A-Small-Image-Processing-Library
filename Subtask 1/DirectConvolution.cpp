#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
// #include "./padding.cpp"
#include "./ConvolutionByMultiplication.cpp"
using namespace std;

vector<vector<float>> invertKernel(vector<vector<float>>& kernel) {
    vector<float> kernel1D = changeTo1D(kernel);
    reverse(kernel1D.begin(), kernel1D.end());
    kernel = changeToSqaure2D(kernel1D);
    return kernel;
}

vector<vector<float>> mapping(vector<vector<float>> kernel, vector<vector<float>> matrix, bool convolution, bool padding=false) {
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

/*
int main() {
    vector<vector<float>> a{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<float>> b{{1, 2, 2, 2, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
    print2DSquareMatrix(mapping(a, b, false));
    print2DSquareMatrix(mapping(a, b, true));
    print2DSquareMatrix(mapping(a, b, false, true));
    return 0;
}
*/
