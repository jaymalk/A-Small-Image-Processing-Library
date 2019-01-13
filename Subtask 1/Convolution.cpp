#include <iostream>
#include <vector>
#include <array>
#include <cmath>
using namespace std;

vector<vector<float>> convert_to_multiplicable_matrix(vector<vector<float>> matrix, int kernel_size) {
  vector<vector<float>> toeplitz{};
  for(int i=0; i<matrix.size()-kernel_size+1; i++) {
    for(int j=0; j<matrix.size()-kernel_size+1; j++) {
      vector<float> row{};
      for(int k=0; k<kernel_size; k++) {
        for(int l=0; l<kernel_size; l++) {
          row.push_back(matrix[i+k][j+l]);
        }
      }
      toeplitz.push_back(row);
    }
  }
  return toeplitz;
}

vector<float> multiply_matrices(vector<vector<float>> toeplitz, vector<float> kernel) {
  vector<float> product;
  for(int i=0; i<toeplitz.size(); i++) {
    float val=0.0;
    for(int j=0; j<kernel.size(); j++)
      val += (toeplitz[i][j]*kernel[j]);
    product.push_back(val);
  }
  return product;
}

vector<float> convert_to_1D(vector<vector<float>> kernel) {
  vector<float> kernel1D(kernel[0].begin(), kernel[0].end());
  for(int i=1; i<kernel.size(); i++)
    kernel1D.insert(kernel1D.end(), kernel[i].begin(), kernel[i].end());
  return kernel1D;
}

vector<vector<float>> convert_to_2D(vector<float> col) {
  vector<vector<float>> matrix;
  int size = (int)(sqrt(col.size()));
  for(int i=0; i<size; i++)
    matrix.push_back(vector<float>(col.begin()+i*size, col.begin()+(i+1)*size));
  return matrix;
}

vector<vector<float>> convolution_by_multiplication(vector<vector<float>> kernel, vector<vector<float>> matrix) {
  vector<float> kernel1D = convert_to_1D(kernel);
  vector<vector<float>> toeplitz = convert_to_multiplicable_matrix(matrix, kernel.size());
  vector<float> conv1d = multiply_matrices(toeplitz, kernel1D);
  return convert_to_2D(conv1d);
}

void print2D(vector<vector<float>> c) {
  for(int i=0; i<c.size(); i++) {
    for(int j=0; j<c[i].size(); j++)
      cout << c[i][j] << " ";
    cout << "\n";
  }
}

void print1D(vector<float> c) {
  for(int i=0; i<c.size(); i++)
    cout << c[i] << " ";
  cout << "\n";
}

int main() {
  vector<vector<float>> a{{1, 0, 1}, {1, -1, 1}, {1, 0, 1}};
  vector<vector<float>> b{{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
  vector<vector<float>> c = convolution_by_multiplication(a, b);
  print2D(c);
  return 0;
}
