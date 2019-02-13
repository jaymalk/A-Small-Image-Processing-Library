#include <iostream>

#include "../func/pool.h"
#include "../io/AIO.h"

#ifndef L4
#define L4

vector<vector<float>> grid_l4;


// Pool the arrays in matrix form and then convert back to array in the same location
double * pool_l4(double * matrix) {
    grid_l4 = convertToSquareMatrix(matrix, 8);   // Convert to vector of vectors
    maxPool(grid_l4);      // Average pool, fiter size = 2, stride  = 2
    free(matrix);       // Freeing the previous loaded matrix
    return convertToArray(grid_l4);      // Storing the new pooled array in old positon
}


// Taking input the input_channel, in this case, the array of 20 matrices
double **pool_layer_l4(double **inchnl) {
    for(int i=0; i<50; i++)
        inchnl[i] = pool_l4(inchnl[i]);
    return inchnl;
}

#endif
