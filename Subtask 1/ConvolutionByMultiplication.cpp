#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "./padding.cpp"
using namespace std;


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

/* The encapsulating layer for complete function
 First two parameters are kernel and matrix, resp.
 Third for selection between convolution (true) and cross-correlation (false)
 To include padding additional argument 'boolean' shall sumise*/
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

/* Print a 2D square matrix */
void print2DSquareMatrix(vector<vector<float>> c) {
        for(int i=0; i<c.size(); i++) {
                for(int j=0; j<c[i].size(); j++)
                        printf("%5.2f ", c[i][j]);
                cout << "\n";
        }
}

/* Print a 1D matrix */
void print1DMatrix(vector<float> c) {
        for(int i=0; i<c.size(); i++)
                cout << c[i] << " ";
        cout << "\n";
}

/*
int main() {
  vector<vector<float>> a{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<float>> b{{1, 2, 2, 2, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};

  // Check for convolution without padding
  vector<vector<float>> c = convolutionByMultiplication(a, b, true);
  print2DSquareMatrix(c);

  // Check for cross-correlation without padding
  c = convolutionByMultiplication(a, b, false);
  print2DSquareMatrix(c);

  // Check for conversion to invert-transpose
  // print2DSquareMatrix(a);
  // vector<float> test = changeTo1D(a);
  // reverse(test.begin(), test.end());
  // print2DSquareMatrix( changeToSqaure2D(test) );

  // Check for convolution with padding
  c = convolutionByMultiplication(a, b, false, true);
  print2DSquareMatrix(c);

  // Check for cross-correlation with padding
  c = convolutionByMultiplication(a, b, false, true);
  print2DSquareMatrix(c);
  return 0;
}
*/
