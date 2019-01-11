#include <vector>
using namespace std;

#ifndef ACTIVATION_H
#define ACTIVATION_H
    vector<float> sigmoid(vector<float> arr);
    vector<float> softmax(vector<float> arr);
    
    vector<vector<int>> relu(vector<vector<int>> matrix);
    vector<vector<float>> relu(vector<vector<float>> matrix);
    
    vector<vector<float>> tanh(vector<vector<int>> matrix);
    vector<vector<float>> tanh(vector<vector<float>> matrix);
#endif