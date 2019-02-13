#include <iostream>
#include <fstream>
#include <vector>

#include "../../func/conv/convolution_without_threading.h"

#ifndef L5V
#define L5V

bool readyl5 = false;
vector<vector<vector<vector<float>>>> filters_l5;
vector<float> weights_l5;

vector<vector<vector<vector<float>>>> input_filters_l5() {
    ifstream l5f("./include/lyrs/wts/fc1.txt");
    vector<vector<vector<vector<float>>>> l5{};
    string data;
    for(int l=0; l<500; l++) {
        vector<vector<vector<float>>> l5_filter_layer{};
        for(int i=0; i<50; i++) {
            vector<vector<float>> filterl5{};
            for(int j=0; j<4; j++) {
                vector<float> rowl1{};
                for(int k=0; k<4; k++) {
                    getline(l5f, data);
                    rowl1.push_back(stof(data));
                }
                filterl5.push_back(rowl1);
            }
            l5_filter_layer.push_back(filterl5);
        }
        l5.push_back(l5_filter_layer);
    }
    vector<float> wts{};
    for(int i=0; i<500; i++) {
        getline(l5f, data);
        wts.push_back(stof(data));
    }
    weights_l5 = wts;
    readyl5 = true;
    return l5;
}

float convolve_complete_layer(vector<vector<vector<float>>> layer_l5, vector<vector<vector<float>>> in_chnl_l5) {
    float result = 0.0;
    for(int i=0; i<50; i++)
        result += (directConvolution(layer_l5[i], in_chnl_l5[i], false))[0][0];
    return (result>0.0)?(result):(0);
}

vector<float> convolve_layer_l5(vector<vector<vector<float>>> in_chnl_l5) {
    if(!readyl5)
        filters_l5 = input_filters_l5();

    vector<float> out_chnl{};
    for(int i=0; i<500; i++) {
        out_chnl.push_back(convolve_complete_layer(filters_l5[i], in_chnl_l5)+weights_l5[i]);
    }
    return out_chnl;
}

#endif
