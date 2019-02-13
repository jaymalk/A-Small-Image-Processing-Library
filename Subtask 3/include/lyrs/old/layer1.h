#include <iostream>
#include <fstream>

#include "../func/conv/toeplitz.h"
#include "../impl/TMM.h"
#include "../io/AIO.h"
#include "../io/IO.h"


#ifndef L1
#define L1

double *filters_l1[20];            // Permanent reserve of filters_l1, requres only one time loading
double weight_l1[20];              // Weights associated with each filter
double **output_channels;    // The output channel to be processed, global so that passing doesnt require parameters

bool readyl1 = false;


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
            filter[i] = stod(data);      // Storing the filter NOT in inverted form to, as required facilitate convolution
        }
        filters_l1[j] = filter;            // Storing the created filter in position
    }
    for(int i=0; i<20; i++) {
        getline(l1filters, data);
        weight_l1[i] = stod(data);
    }
    readyl1 = true;           // Variable set once data is stored
}

void add_weight_l1(double *C, int i) {
    double wt = weight_l1[i];
    for(int i=0; i<24*24; i++)
        C[i] += wt;
}


double * convolve_l1(int i, double * mat_toep) {
        int row = 24*24;
        int col = 25;
        double *C = (double *)malloc(sizeof(double) * row);
        C = call_multiplication(mat_toep, row, filters_l1[i], col, C);
        // To add associated weight_l1 to each channel
        add_weight_l1(C, i);
        return C;
}


double ** convolve_layer_l1(double *matrix) {
    output_channels = (double **)malloc(sizeof(double *));

    if(!readyl1)                                               // If filter is already prepared use it
        input_data_l1();                                         // Else create new one and store it

    double *mat_toep = convertToToeplitzForm(matrix, 28, 5);            // Convert the main matrix to toeplitz form, to be used on all filters_l1

    for(int i=0; i<20; i++)
        output_channels[i] = convolve_l1(i, mat_toep);

    ofstream out("fitlers.txt");
    for(int i=0; i<20; i++) {
        printMatrix(convertToSquareMatrix(filters_l1[i], 5), out);
    }

    return output_channels;
}

#endif
