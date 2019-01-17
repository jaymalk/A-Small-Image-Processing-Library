#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
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
        vector<float> temp{};
        try {
            ifstream input(filename);
            if(!input.good())
                throw runtime_error("File \'"+filename+ "\' doesn't exit or is not readable.\n");
            string line;
            while(getline(input, line))
                try {
                    temp.push_back(stof(line));
                }
                catch(...) {
                    throw runtime_error("Non-float values in file \'"+filename+ "\', please check.\n");
                }
            int size = (int)(temp.size());
            if(size%numRows != 0)
                throw runtime_error("Error in relating num_rows, not a matrix.\n");
            for(int i=0; i<numRows; i++) {
                matrix.push_back(vector<float>{});
                for(int j=0; j< (int)(size/numRows); j++)
                    matrix[i].push_back(temp[j*numRows+i]);
            }
        }
        catch(const runtime_error& e) {
            throw e;
        }
        catch(...) {
            throw runtime_error("Some Problem [File I/O] [Emptry Matrix Returned]\n");
        }
        return matrix;
    }

    /* If number of rows is not a predetermined number */
    vector<vector<float>> inputSquareMatrix(string filename) {
        vector<vector<float>> matrix;
        vector<float> temp{};
        try {
            ifstream input(filename);
            if(!input.good())
                throw runtime_error("File \'"+filename+ "\' doesn't exit or is not readable.\n");
            string line;
            while(getline(input, line))
                try {
                    temp.push_back(stof(line));
                }
                catch(...) {
                    throw runtime_error("Non-float values in file \'"+filename+ "\', please check.\n");
                }

            int size = (int)(sqrt(temp.size()));
            if(size*size != temp.size())
                throw runtime_error("Input file- \'"+filename+"\' is not a square matrix.\n");
            for(int i=0; i<size; i++) {
                matrix.push_back(vector<float>{});
                for(int j=0; j<size; j++)
                    matrix[i].push_back(temp[j*size+i]);
            }
        }
        catch(const runtime_error& e) {
            throw e;
        }
        catch(...) {
            throw runtime_error("Some Problem [File I/O] [Emptry Matrix Returned]\n");
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
            if(!input.good())
                throw runtime_error("File \'"+filename+ "\' doesn't exit or is not readable.\n");
            string line;
            while(getline(input, line))
                try {
                    cout << line;
                    vctr.push_back(stof(line));
                }
                catch(...) {
                    throw runtime_error("Non-float values in file \'"+filename+ "\', please check.\n");
                }
        }
        catch(const runtime_error& e) {
            throw e;
        }
        catch(...) {
            throw runtime_error("Some Problem [File I/O] [Emptry Vector Returned]");
        }
        return vctr;
    }


    // OUTPUT
    /* Print/write a 2D square matrix */
    void writeMatrix(vector<vector<float>> c, ostream& out=cout) {
        for(int i=0; i<c[0].size(); i++)
                for(int j=0; j<c.size(); j++)
                        out << setprecision(14) << c[j][i] << "\n";
    }

    /* Print/write a 1D vector */
    void writeVector(vector<float> c, ostream &out = cout) {
        for(int i=0; i<c.size(); i++)
                out << setprecision(14) << c[i] << "\n";
    }

#endif
