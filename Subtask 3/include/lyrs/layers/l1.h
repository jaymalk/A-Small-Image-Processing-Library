#include <iostream>
#include <vector>
#include <fstream>

#include "../../func/conv/convolution_without_threading.h"

using namespace std;

#ifndef L1V
#define L1V

/* HEADER FILE CONTAINING FEATURES THAT CONTAINS
  FUNCTIONS TO IMPLEMENT LAYER FEATURES WITH VECTORS
*/

bool readyl1 = false;
vector<vector<vector<float>>> filtersl1;
vector<float> weights_l1;

vector<vector<vector<float>>> input_filters_l1() {
    ifstream l1f("./include/lyrs/wts/conv1.txt");
    vector<vector<vector<float>>> l1{};
    string data;
    for(int i=0; i<20; i++) {
        vector<vector<float>> filterl1{};
        for(int j=0; j<5; j++) {
            vector<float> rowl1{};
            for(int k=0; k<5; k++) {
                getline(l1f, data);
                rowl1.push_back(stof(data));
            }
            filterl1.push_back(rowl1);
        }
        l1.push_back(filterl1);
    }
    vector<float> wts{};
    for(int i=0; i<20; i++) {
        getline(l1f, data);
        wts.push_back(stof(data));
    }
    weights_l1 = wts;
    readyl1 = true;
    return l1;
}

void add_weight_l1(vector<vector<float>>& matrix, float weight) {
    for(vector<float>& row : matrix)
        for(float& val : row)
            val += weight;
}

vector<vector<vector<float>>> convolve_layer_l1(vector<vector<float>> matrix) {
    if(!readyl1)
        filtersl1 = input_filters_l1();

    vector<vector<vector<float>>> out_channel_l1{};
    for(vector<vector<float>> fl1 : filtersl1)
        out_channel_l1.push_back(convolutionByMultiplication(fl1, matrix, false));

    for(int i=0; i<20; i++)
        add_weight_l1(out_channel_l1[i], weights_l1[i]);

    return out_channel_l1;
}

#endif
