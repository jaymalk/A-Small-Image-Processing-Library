#include <iostream>
#include <fstream>
#include <vector>

#include "../../func/conv/convolution_without_threading.h"

#ifndef L3V
#define L3V

bool readyl3 = false;
vector<vector<vector<vector<float>>>> filtersl3;
vector<float> weights_l3;

vector<vector<vector<vector<float>>>> input_filters_l3() {
    ifstream l3f("./include/lyrs/wts/conv2.txt");
    vector<vector<vector<vector<float>>>> l3{};
    string data;
    for(int l=0; l<50; l++) {
        vector<vector<vector<float>>> l3_filter_layer{};
        for(int i=0; i<20; i++) {
            vector<vector<float>> filterl3{};
            for(int j=0; j<5; j++) {
                vector<float> rowl1{};
                for(int k=0; k<5; k++) {
                    getline(l3f, data);
                    rowl1.push_back(stof(data));
                }
                filterl3.push_back(rowl1);
            }
            l3_filter_layer.push_back(filterl3);
        }
        l3.push_back(l3_filter_layer);
    }
    vector<float> wts{};
    for(int i=0; i<50; i++) {
        getline(l3f, data);
        wts.push_back(stof(data));
    }
    weights_l3 = wts;
    readyl3 = true;
    return l3;
}

void add_weight_l3(vector<vector<float>>& matrix, float weight) {
    for(vector<float>& row : matrix)
        for(float& val : row)
            val += weight;
}

void add_matrices(vector<vector<float>>& m1, vector<vector<float>> m2) {
    for(int i=0; i<m1.size(); i++)
        for(int j=0; j<m1.size(); j++)
            m1[i][j] += m2[i][j];
}

vector<vector<float>> convolve_layer_and_add(vector<vector<vector<float>>> layer_l3, vector<vector<vector<float>>> in_chnl_l3) {
    vector<vector<float>> result(8, vector<float>(8, 0));
    for(int i=0; i<20; i++)
        add_matrices(result, convolutionByMultiplication(layer_l3[i], in_chnl_l3[i], false));
    return result;
}

vector<vector<vector<float>>> convolve_layer_l3(vector<vector<vector<float>>> in_chnl_l3) {
    if(!readyl3)
        filtersl3 = input_filters_l3();

    vector<vector<vector<float>>> out_chnl{};
    for(int i=0; i<50; i++) {
        out_chnl.push_back(convolve_layer_and_add(filtersl3[i], in_chnl_l3));
        add_weight_l3(out_chnl[i], weights_l3[i]);
    }
    return out_chnl;
}

#endif
