#include <iostream>
#include <fstream>

#include "../func/conv/convolution_threaded.h"
#include "../func/conv/toeplitz.h"
#include "../io/AIO.h"
#include "../io/IO.h"


#ifndef L1
#define L1

double *filters[20];            // Permanent reserve of filters, requres only one time loading
double weight[20];              // Weights associated with each filter
double **output_channels;    // The output channel to be processed, global so that passing doesnt require parameters

bool ready = false;


/*
    Inputing the data. (Considering row major order)
    Only a one time job, kept in check by the ready variable.
*/
void input_data_l1() {
    ifstream l1filters("./wts/conv1.txt");
    string data;
    for(int j=0; j<20; j++) {
        double *filter = (double *)malloc(25*(sizeof(double)));
        for(int i=0; i<25; i++) {
            getline(l1filters, data);
            filter[24-i] = stod(data);      // Storing the filter in inverted form to facilitate convolution
        }
        filters[j] = filter;            // Storing the created filter in position
    }
    for(int i=0; i<20; i++) {
        getline(l1filters, data);
        weight[i] = stod(data);
    }
    ready = true;           // Variable set once data is stored
}

void add_weight(double *C, int i) {
    double wt = weight[i];
    for(int i=0; i<24*24; i++)
        C[i] += wt;
}


double * convolve_l1(int i, double * mat_toep) {

        int row = 24*24;            // Simple convolution module
        int col = 25;

        double *C = (double *)malloc(sizeof(double) * row);
        C = call_multiplication(mat_toep, row, filters[i], col, C);

        add_weight(C, i);       // To add associated weight to each channel
        return C;
}


double ** convolve_layer_l1(double *matrix) {
    output_channels = (double **)malloc(sizeof(double *));

    if(!ready)                                               // If filter is already prepared use it
        input_data_l1();                                         // Else create new one and store it

    double *mat_toep = convertToToeplitzForm(matrix, 28, 5);            // Convert the main matrix to toeplitz form, to be used on all filters

    for(int i=0; i<20; i++)
        output_channels[i] = convolve_l1(i, mat_toep);

    ofstream out("fitlers.txt");
    for(int i=0; i<20; i++) {
        printMatrix(convertToSquareMatrix(filters[i], 5), out);
    }

    return output_channels;
}

#endif
