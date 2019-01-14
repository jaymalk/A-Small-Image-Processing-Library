#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

#ifndef IO_H
#define IO_H
    // INPUT
    /* Input a matrix from a file.
    The matrix is assumed to be in column major order.
    Number of rows is not a predetermined number. */
    vector<vector<float>> inputMatrix(string filename) {
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
    vector<float> inputVector(string filename) {
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


    // OUTPUT
    /* Print/write a 2D square matrix */
    void writeSquareMatrix(vector<vector<float>> c, ostream& out=cout) {
        for(int i=0; i<c.size(); i++) {
                for(int j=0; j<c[i].size(); j++)
                        out<< setw(8) << c[i][j];
                out << "\n";
        }
    }

    /* Print/write a 1D vector */
    void writeVector(vector<float> c, ostream &out = cout) {
        for(int i=0; i<c.size(); i++)
                out << c[i] << " ";
        out << "\n";
    }
    
#endif
