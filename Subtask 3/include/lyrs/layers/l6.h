#include <iostream>
#include <vector>
#include <fstream>

#include "../../func/activation.h"

#ifndef L6V
#define L6V

bool readyl6 = false;
vector<vector<float>> filters_l6;
vector<float> weights_l6;

vector<vector<float>> input_filters_l6() {
    ifstream l6f("./include/lyrs/wts/fc2.txt");
    string data;
    vector<vector<float>> l6{};
    for(int i=0; i<10; i++) {
        vector<float> l6_filter{};
        for(int j=0; j<500; j++) {
            getline(l6f, data);
            l6_filter.push_back(stof(data));
        }
        l6.push_back(l6_filter);
    }
    vector<float> wts{};
    for(int i=0; i<10; i++) {
        getline(l6f, data);
        wts.push_back(stof(data));
    }
    weights_l6 = wts;
    readyl6 = true;
    return l6;
}

float dot_product(vector<float> layer_l6, vector<float> in_chnl_l6) {
    float result = 0.0;
    for(int i=0; i<500; i++)
        result += (layer_l6[i]*in_chnl_l6[i]);
    return result;
}

vector<float> convolve_layer_l6(vector<float> in_chnl_l6) {
    if(!readyl6)
        filters_l6 = input_filters_l6();

    vector<float> out_chnl{};
    for(int i=0; i<10; i++) {
        out_chnl.push_back(dot_product(filters_l6[i], in_chnl_l6)+weights_l6[i]);
    }
    return softmax(out_chnl);
}

#endif
