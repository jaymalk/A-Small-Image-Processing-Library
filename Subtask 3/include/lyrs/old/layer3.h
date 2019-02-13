#include <iostream>
#include <fstream>

#include "../func/conv/toeplitz.h"
#include "../impl/TMM.h"


#ifndef L3
#define L3

double *filters_l3[50][20];            // Permanent reserve of filters_l3, requres only one time loading
double *temp_filters[20];
double weight_l3[50];              // Weights associated with each filter

bool readyl3 = false;


/*
    Inputing the data.
    Only a one time job, kept in check by the ready variable.
*/
void input_data_l3() {
    ifstream l3filters("./wts/conv2.txt");
    string data;
    for(int j=0; j<50; j++)
        for(int k=0; k<20; k++) {
            double *filter = (double *)malloc(25*(sizeof(double)));
            for(int i=0; i<25; i++) {
                getline(l3filters, data);
                filter[i] = stod(data);       // Storing the filter NOT in inverted form to, as required facilitate convolution
            }
            filters_l3[j][k] = filter;            // Sorting the created filter in position
        }
    for(int i=0; i<50; i++) {
        getline(l3filters, data);
        weight_l3[i] = stod(data);
    }
    readyl3 = true;           // Variable set once data is stored
}

void add_weight_l3(double *C, int i) {
    double wt = weight_l3[i];
    for(int i=0; i<64; i++)
        C[i] += wt;
}

void add_matrix_l3(double *first, double *addend) {
    for(int i=0; i<64; i++)
        addend[i] = first[i]+addend[i];
}

double * convolve_with_sum_l3(int i, double ** inchnl) {
    double *result = (double *)malloc(sizeof(double)*8*8);
    for(int j=0; j<20; j++) {
        double *C = (double *)malloc(sizeof(double)*64);
        C = call_multiplication(convertToToeplitzForm(inchnl[j], 12, 5), 64, filters_l3[i][j], 25, C);
        add_matrix_l3(C, result);
    }
    return result;
}

double ** convolve_layer_l3(double ** inchnl) {
    double ** output_channel = (double **)malloc(50*sizeof(double *));
    if(!readyl3)              // If filter is already prepared use it
        input_data_l3();        // Else create new one and store it
    for(int i=0; i<50; i++)
        output_channel[i] = convolve_with_sum_l3(i, inchnl);              // Perform convolution
    return output_channel;
}

#endif
