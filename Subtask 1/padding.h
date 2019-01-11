#include <vector>
using namespace std;

#ifndef PADDING_H
#define PADDING_H
    vector<vector<float>> pad(vector<vector<float>> matrix, int padSize=1);
    vector<vector<int>> pad(vector<vector<int>> matrix, int padSize=1);
#endif