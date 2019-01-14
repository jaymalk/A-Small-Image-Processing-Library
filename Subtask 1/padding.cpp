#include <vector>
//#include <iostream>
using namespace std;

//For int
vector<vector<int>> pad(vector<vector<int>> matrix, int padSize=1){
    const int SIZE = matrix.size();

    if(SIZE<=0)
        throw runtime_error("Empty matrix. Can't Pad");
    
    int columnSize = matrix[0].size();

    if(columnSize != SIZE)
        throw runtime_error("Not a square matrix. This function is meant to only pad square matrices.");
    
    if(padSize<=0){
        throw runtime_error("Invalid Padding Size- Pad Size must be greater than equal to 1");
    }

    int copyPadSize = padSize;
    
    vector<int>:: iterator it;
    
    while(padSize>1){
        for(int i=0; i<SIZE; i++){
            it = matrix[i].insert(matrix[i].begin(), 0);
            matrix[i].push_back(0);
        }
        padSize -= 2;
    }

    if(padSize==1)
        for(int i=0; i<SIZE; i++)
            matrix[i].push_back(0);

    padSize = copyPadSize;
    vector<int> paddingVector(SIZE+padSize);  // vector is implicitly initialized with zero

    while(padSize>1){
        auto it = matrix.insert(matrix.begin(), paddingVector);
        matrix.push_back(paddingVector);
        padSize -= 2;
    }

    if(padSize==1)
        matrix.push_back(paddingVector);

    return matrix;    
}

//For Float
vector<vector<float>> pad(vector<vector<float>> matrix, int padSize=1){
    const int SIZE = matrix.size();

    if(SIZE<=0)
        throw runtime_error("Empty matrix. Can't Pad");
    
    int columnSize = matrix[0].size();

    if(columnSize != SIZE)
        throw runtime_error("Not a square matrix. This function is meant to only pad square matrices.");
    

    if(padSize<=0){
        throw runtime_error("Invalid Padding Size- Pad Size must be greater than equal to 1");
    }

    int copyPadSize = padSize;
    
    vector<float>:: iterator it;
    
    while(padSize>1){
        for(int i=0; i<SIZE; i++){
            it = matrix[i].insert(matrix[i].begin(), 0.0f);
            matrix[i].push_back(0.0f);
        }
        padSize -= 2;
    }

    if(padSize==1)
        for(int i=0; i<SIZE; i++)
            matrix[i].push_back(0.0f);

    padSize = copyPadSize;
    vector<float> paddingVector(SIZE+padSize);  // vector is implicitly initialized with zero

    while(padSize>1){
        auto it = matrix.insert(matrix.begin(), paddingVector);
        matrix.push_back(paddingVector);
        padSize -= 2;
    }
    
    if(padSize==1)
        matrix.push_back(paddingVector);

    return matrix;    
}

/*
int main(){
    vector<vector<int>> v{    {1,2,3}, {-1,3,5}, {-23,123,45}};

    vector<vector<int>> paddedV = pad(v);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<paddedV[i][j]<<" ";
        }
        cout<<endl;
    }
}
*/