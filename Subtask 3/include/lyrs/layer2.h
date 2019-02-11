#include <iostream>

#include "../func/pool.h"
#include "../io/AIO.h"

#ifndef L2
#define L2

vector<vector<float>> grid;


// Pool the arrays in matrix form and then convert back to array in the same location
void pool(double * matrix) {
    grid = convertToSquareMatrix(matrix, 24);   // Convert to vector of vectors
    avgPool(grid);      // Average pool, fiter size = 2, stride  = 2
    free(matrix);       // Freeing the previous loaded matrix
    matrix = convertToArray(grid);      // Storing the new pooled array in old positon
}


// Taking input the input_channel, in this case, the array of 20 matrices
double **pool_layer_l2(double *in_channel[20]) {
    for(double *channel : in_channel)
        pool(channel);
    return in_channel;
}

#endif
