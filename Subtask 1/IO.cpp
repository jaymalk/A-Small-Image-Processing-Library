#include <iostream>
#include <fstream>
#include <sstream>
#include "./ConvolutionByMultiplication.cpp"
#include <vector>
using namespace std;

/* Input a matrix from a file.
   The matrix is assumed to be in column major order.
   Number of rows is not a predetermined number. */
vector<vector<float>> input_matrix(string filename) {
    vector<vector<float>> matrix;
    try {
        ifstream input(filename);
        string line;
        getline(input, line);
        float val{};
        istringstream s(line);
        while(s >> val)
            matrix.push_back(vector<float>{val});
        int matrixSize = matrix.size();
        for(int i=1; i<matrixSize; i++) {
            getline(input, line);
            istringstream s(line);
            for(int j=0; j<matrixSize; j++) {
                s >> val;
                matrix[j].push_back(val);
            }
        }
    }
    catch(...) {

    }
    return matrix;
}

/* Input a vector from a file.
    The vector is assumed to be in a single line.
    Size is not known.
*/
vector<float> input_vctr(string filename) {
    vector<float> vctr{};
    try {
        ifstream input(filename);
        string line;
        float val{};
        getline (input, line);
        istringstream s(line);
        while (s >> val) {
            vctr.push_back(val);
        }
    }
    catch(...) {
        cout << "Some Problem [File I/O] [Emptry Matrix Returned]" << "\n";
    }
    return vctr;
}

/*
int main() {
    for(int i=3; i<10; i++) {
        // print1DMatrix(input_vctr("./Vectors/vector_"+to_string(i)+".txt"));
        print2DSquareMatrix(input_matrix("./Matrices/matrix_"+to_string(i)+".txt"));
        cout << "\n\n";
    }
}
*/
