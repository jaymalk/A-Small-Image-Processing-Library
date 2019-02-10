#include <iostream>
#include <fstream>

#include "../func/conv/convolution_threaded.h"
#include "../func/conv/toeplitz.h"


#ifndef L1
#define L1

double *filters[20];
double weight[20];
double *output_channels[20];

bool ready = false;


/*
    Inputing the data.
    Only a one time job, kept in check by the ready variable.
*/
void input_data_l1() {
    ifstream l1filters("./wts/conv1.txt");
    string data;
    for(int i=0; i<20; i++) {
        double *filter = (double *)malloc(25*(sizeof(double)));
        for(int i=0; i<25; i++) {
            getline(l1filters, data);
            filter[24-i] = stod(data);      // Storing the filter in inverted form to facilitate convolution
        }
        filters[i] = filter;
    }
    for(int i=0; i<20; i++) {
        getline(l1filters, data);
        weight[i] = stod(data);
    }
    ready = true;
}

void add_weight(double *C, int i) {
    double wt = weight[i];
    for(int i=0; i<24; i++)
        C[i] += wt;
}

double * convolve_l1(int i, double * mat_toep) {

        int row = 24*24;
        int col = 25;

        double *B = filters[i];
        double *T = mat_toep;

        double *C = (double *)malloc(sizeof(double) * row);
        C = call_multiplication(T, row, B, col, C);

        add_weight(C, i);

        return C;
}

double * convolve_layer_l1(double *matrix, double *output_channel) {
    if(!ready)
        input_data_l1();
    double *mat_toep = convertToToeplitzForm(matrix, 28, 5);
    for(int i=0; i<20; i++)
        output_channels[i] = convolve_l1(i, mat_toep);
    return output_channels;
}

#endif
