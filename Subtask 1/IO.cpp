#include <iostream>
#include <fstream>
#include "./ConvolutionByMultiplication.cpp"
#include <vector>
using namespace std;

/* Input a matrix from a file.
   The matrix is assumed to be in column major order.
   Number of rows is a predetermined number. */
vector<vector<float>> input_matrix(string filename, int num_rows) {
    vector<vector<float>> matrix{};
    try {
        ifstream input(filename);
        float val{};
        for(int i=0; i<num_rows; i++) {
            input >> val;
            vector<float> a{val};
            matrix.push_back(a);
        }
        for(int i=1; i<num_rows; i++)
            for(int j=0; j<num_rows; j++) {
                input >> val;
                matrix[j].push_back(val);
            }
    }
    catch(...) {
        cout << "Some Problem [File I/O] [Emptry Matrix Returned]" << "\n";
    }
    return matrix;
}

///*
int main() {
    for(int i=3; i<10; i++) {
        print2DSquareMatrix(input_matrix("./Matrices/matrix_"+to_string(i)+".txt", i));
        cout << "\n\n";
    }
}
//*/
