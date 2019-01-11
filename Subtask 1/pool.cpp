#include <vector>
#include "padding.h"
using namespace std;

vector<vector<int>> maxPool(vector<vector<int>> matrix, int filterSize = 2, int stride = 2 ){
    
    if(filterSize <= 0)
        throw "Invalid filter size";
    if(stride <= 0)
        throw "Invalid stride";

    const int SIZE = matrix.size();
    int padSize = (SIZE-filterSize)%stride;

    if(padSize > 0){
        padSize = stride - padSize; 
        matrix = pad(matrix, padSize);
    }
    
    int poolMatrixSize = 1 + (SIZE+padSize-filterSize)/stride;   
    vector<vector<int>> pooledMatrix(poolMatrixSize);

    int row = 0;
    for(int i=0; i<SIZE+padSize; i+=stride){
        pooledMatrix[row] = vector<int>(poolMatrixSize);
        
        int column = 0;
        for(int j=0; j<SIZE+padSize; j+=stride){
            
            int max = matrix[i][j];
            
            for(int a=i; a<i+filterSize; a++)
                for(int b=j; b<j+filterSize; b++)
                    if(matrix[a][b]>max)
                        max=matrix[a][b];
            
            pooledMatrix[row][column] = max;
            column++;
        }
        row++;
    } 

    return pooledMatrix;
}   

vector<vector<float>> maxPool(vector<vector<float>> matrix, int filterSize = 2, int stride = 2 ){
    
    if(filterSize <= 0)
        throw "Invalid filter size";
    if(stride <= 0)
        throw "Invalid stride";

    const int SIZE = matrix.size();
    int padSize = (SIZE-filterSize)%stride;

    if(padSize > 0){
        padSize = stride - padSize; 
        matrix = pad(matrix, padSize);
    }
    
    int poolMatrixSize = 1 + (SIZE+padSize-filterSize)/stride;   
    vector<vector<float>> pooledMatrix(poolMatrixSize);

    int row = 0;
    for(int i=0; i<SIZE+padSize; i+=stride){
        pooledMatrix[row] = vector<float>(poolMatrixSize);
        
        int column = 0;
        for(int j=0; j<SIZE+padSize; j+=stride){
            
            float max = matrix[i][j];
            
            for(int a=i; a<i+filterSize; a++)
                for(int b=j; b<j+filterSize; b++)
                    if(matrix[a][b]>max)
                        max=matrix[a][b];
            
            pooledMatrix[row][column] = max;
            column++;
        }
        row++;
    } 

    return pooledMatrix;
}   

vector<vector<float>> avgPool(vector<vector<int>> matrix, int filterSize = 2, int stride = 2 ){
    if(filterSize <= 0)
        throw "Invalid filter size";
    if(stride <= 0)
        throw "Invalid stride";

    const int SIZE = matrix.size();
    int padSize = (SIZE-filterSize)%stride;

    if(padSize > 0){
        padSize = stride - padSize; 
        matrix = pad(matrix, padSize);
    }
    
    int poolMatrixSize = 1 + (SIZE+padSize-filterSize)/stride;   
    vector<vector<float>> pooledMatrix(poolMatrixSize);

    int row = 0;
    for(int i=0; i<SIZE+padSize; i+=stride){
        pooledMatrix[row] = vector<float>(poolMatrixSize);
        
        int column = 0;
        for(int j=0; j<SIZE+padSize; j+=stride){
            
            float sum = 0.0f;
            
            for(int a=i; a<i+filterSize; a++)
                for(int b=j; b<j+filterSize; b++)
                    sum+=matrix[a][b];
            
            pooledMatrix[row][column] = sum/(filterSize*filterSize);
            column++;
        }
        row++;
    } 

    return pooledMatrix;
}

vector<vector<float>> maxPool(vector<vector<float>> matrix, int filterSize = 2, int stride = 2 ){
    if(filterSize <= 0)
        throw "Invalid filter size";
    if(stride <= 0)
        throw "Invalid stride";

    const int SIZE = matrix.size();
    int padSize = (SIZE-filterSize)%stride;

    if(padSize > 0){
        padSize = stride - padSize; 
        matrix = pad(matrix, padSize);
    }
    
    int poolMatrixSize = 1 + (SIZE+padSize-filterSize)/stride;   
    vector<vector<float>> pooledMatrix(poolMatrixSize);

    int row = 0;
    for(int i=0; i<SIZE+padSize; i+=stride){
        pooledMatrix[row] = vector<float>(poolMatrixSize);
        
        int column = 0;
        for(int j=0; j<SIZE+padSize; j+=stride){
            
            float sum = 0.0f;
            
            for(int a=i; a<i+filterSize; a++)
                for(int b=j; b<j+filterSize; b++)
                    sum+=matrix[a][b];
            
            pooledMatrix[row][column] = sum/(filterSize*filterSize);
            column++;
        }
        row++;
    } 
    return pooledMatrix;
}