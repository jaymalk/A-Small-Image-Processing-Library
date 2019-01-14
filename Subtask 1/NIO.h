#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;

/* Another input file to suit the required input parameters */

#ifndef NIO_H
#define NIO_H
    // INPUT
    /* Input a matrix from a file.
    The matrix is assumed to be in column major order.
    Number of rows is a predetermined number. */
    vector<vector<float>> inputMatrix(string filename, int numRows) {
        vector<vector<float>> matrix;
        try {
            ifstream input(filename);
            string line;
            for(int i=0; i<numRows; i++) {
                getline(input, line);
                matrix.push_back(vector<float>{(float)stoi(line)});
            }
            for(int j=1; j<numRows; j++)
                for(int i=0; i<numRows; i++) {
                    getline(input, line);
                    matrix[i].push_back((float)stoi(line));
                }
        }
        catch(...) {
            throw runtime_error("Some Problem [File I/O] [Emptry Matrix Returned]");
        }
        return matrix;
    }

    /* If number of rows is not a predetermined number */
    vector<vector<float>> inputMatrix(string filename) {
        vector<vector<float>> matrix;
        vector<float> temp{};
        try {
            ifstream input(filename);
            string line;
            while(getline(input, line))
                temp.push_back((float)stoi(line));
            int size = (int)(sqrt(temp.size()));
            assert(size*size == temp.size());
            for(int i=0; i<size; i++) {
                matrix.push_back(vector<float>{});
                for(int j=0; j<size; j++)
                    matrix[i].push_back(temp[j*size+i]);
            }
        }
        catch(...) {
            throw runtime_error("Some Problem [File I/O] [Emptry Matrix Returned]");
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
            while(getline(input, line))
                vctr.push_back((float)stoi(line));
        }
        catch(...) {
            throw runtime_error("Some Problem [File I/O] [Emptry Matrix Returned]");
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
