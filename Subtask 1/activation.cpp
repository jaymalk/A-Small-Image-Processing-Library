#include <vector>
#include <cmath>
//#include <iostream>

using namespace std;

//Parameter Passing for vectors is Pass by value.

vector<float> sigmoid(vector<float> arr){
    const int SIZE = arr.size();

    for(int i=0; i<SIZE; i++)
        arr[i] = 1.0/(1+exp(-1*arr[i]));

    return arr;
}


vector<float> softmax(vector<float> arr){
    const int SIZE = arr.size();
    float sum=0.0f;

    for(int i=0; i<SIZE; i++){
        arr[i] = exp(arr[i]);
        sum += arr[i];
    }

    for(int i=0;i <SIZE;i ++)
        arr[i] /= sum;

    return arr;
}

vector<vector<int>> relu(vector<vector<int>> matrix){
    const int SIZE = matrix.size();

    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            matrix[i][j] = max(0, matrix[i][j]);

    return matrix;
}

vector<vector<float>> relu(vector<vector<float>> matrix){
    const int SIZE = matrix.size();

    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            matrix[i][j] = max(0.0f, matrix[i][j]);

    return matrix;
}

vector<vector<float>> tanh(vector<vector<int>> matrix){
    const int SIZE = matrix.size();
    vector<vector<float>> tanhMatrix(SIZE);              // new matrix due to different data-type of input and output

    for(int i=0; i<SIZE; i++){
        tanhMatrix[i] = vector<float>(SIZE);

        for(int j=0; j<SIZE; j++)
           tanhMatrix[i][j] = 2.0/(1+exp(-2.0*matrix[i][j])) - 1;
    }

    return tanhMatrix;
}


vector<vector<float>> tanh(vector<vector<float>> matrix){
    const int SIZE = matrix.size();
   
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            matrix[i][j] = 2.0/(1+exp(-2.0*matrix[i][j])) - 1;

    return matrix;
}

/*
int main(){
    vector<vector<float>> v{    {1,2,3}, {-1,3,5}, {-23,123,45}};
    vector<vector<float>> computedTANH = tanh(v);
    vector<vector<float>> computedRELU = relu(v);
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<computedTANH[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<computedRELU[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}*/
