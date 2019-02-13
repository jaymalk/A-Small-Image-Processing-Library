#include <iostream>

#include "../func/pool.h"
#include "../io/AIO.h"

#ifndef L2
#define L2

vector<vector<float>> grid;


// Pool the arrays in matrix form and then convert back to array in the same location
double * pool(double * matrix) {
    grid = convertToSquareMatrix(matrix, 24);   // Convert to vector of vectors
    maxPool(grid);      // Average pool, fiter size = 2, stride  = 2
    free(matrix);       // Freeing the previous loaded matrix
    return convertToArray(grid);      // Storing the new pooled array in old positon
}


// Taking input the input_channel, in this case, the array of 20 matrices
double **pool_layer_l2(double **inchnl) {
    for(int i=0; i<20; i++)
        inchnl[i] = pool(inchnl[i]);
    return inchnl;
}

#endif
