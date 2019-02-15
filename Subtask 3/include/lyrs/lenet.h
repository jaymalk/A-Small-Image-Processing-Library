#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

#include "layers/l1.h"
#include "layers/l2.h"
#include "layers/l3.h"
#include "layers/l4.h"
#include "layers/l5.h"
#include "layers/l6.h"

#ifndef LENET
#define LENET

vector<vector<float>> processImage(string filename) {
    const string start = "python ./include/lyrs/process.py "+filename;
    const string end = "rm -f .temp";

    int a = system(start.c_str());
    if(a != 0)
        throw runtime_error("Some problem with python or file "+filename+" doesn't exist.\n");

    string data;
    ifstream file(".temp");

    vector<vector<float>> matrix{};

    for(int i=0; i<28; i++) {
        vector<float> row{};
        for(int j=0; j<28; j++) {
            getline(file, data);
            row.push_back(stof(data));
        }
        matrix.push_back(row);
    }

    int b = system(end.c_str());
    if(b != 0)
        throw runtime_error("Some problem in deleting temp files. Please see.");

    return matrix;
}

void print_formatted(vector<float> data) {
    for(int i=0; i<10; i++) {
        string s = "\nDigit : "+to_string(i)+", Probablilty : "+to_string(data[i]);
        cout << s << "\n";
    }
    cout << "\n";
}

void print_max_formatted(vector<float> data) {
    int max_index = 0;
    for(int i=0; i<10; i++) {
        if(data[i] > data[max_index])
            max_index = i;
    }
    cout << "\nDigit : " << to_string(max_index) << "\nMost Probable, with probability " << to_string(data[max_index]) << "\n\n";
}

void implement_lenet(string filename, int req) {

    vector<vector<float>> matrix = processImage(filename);

    vector<vector<vector<float>>> layer0 = convolve_layer_l1(matrix);

    vector<vector<vector<float>>> layer1 = pool_layer_l2(layer0);

    vector<vector<vector<float>>> layer2 = convolve_layer_l3(layer1);

    vector<vector<vector<float>>> layer3 = pool_layer_l4(layer2);

    vector<float> layer4 = convolve_layer_l5(layer3);

    vector<float> layer5 = convolve_layer_l6(layer4);

    if(req == 1)
    /* Simple digit recognition */
    {
        print_max_formatted(layer5);
    }
    else
    /* Printing the probabilities */
    {
        print_formatted(layer5);
    }
}

#endif
