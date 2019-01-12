#include <vector>
using namespace std;

#ifndef PADDING_H
#define PADDING_H
    vector<vector<int>> maxPool(vector<vector<int>> matrix, int filterSize = 2, int stride = 2 );
    vector<vector<float>> maxPool(vector<vector<float>> matrix, int filterSize = 2, int stride = 2 );

    vector<vector<float>> avgPool(vector<vector<int>> matrix, int filterSize = 2, int stride = 2 );
    vector<vector<float>> avgPool(vector<vector<float>> matrix, int filterSize = 2, int stride = 2 );
#endif