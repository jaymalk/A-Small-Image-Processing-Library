#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

#ifndef IO_H
#define IO_H
    vector<vector<float>> inputMatrix(string filename);
    vector<float> inputVector(string filename);

    void writeSquareMatrix(vector<vector<float>> c, ostream& out=cout);
    void writeVector(vector<float> c, ostream &out = cout);
#endif
