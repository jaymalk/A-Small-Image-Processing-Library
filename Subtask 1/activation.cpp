#include <vector>
#include <cmath>
//#include <iostream>

using namespace std;

vector<float> sigmoid(vector<float> arr){
    const int SIZE = arr.size();
    vector<float> sigmoidVector(SIZE);

    for(int i=0; i<SIZE; i++)
        sigmoidVector[i] = 1.0/(1+exp(-1*arr[i]));

    return sigmoidVector;
}


vector<float> softmax(vector<float> arr){
    const int SIZE = arr.size();
    vector<float> softmaxVector(SIZE);
    float sum=0.0f;

    for(int i=0; i<SIZE; i++){
        softmaxVector[i] = exp(arr[i]);
        sum += softmaxVector[i];
    }

    for(int i=0;i <SIZE;i ++)
        softmaxVector[i] /= sum;

    return softmaxVector;
}

vector<vector<int>> relu(vector<vector<int>> matrix){
    const int SIZE = matrix.size();
    vector<vector<int>> reluMatrix(SIZE);

    for(int i=0; i<SIZE; i++){
        reluMatrix[i] = vector<int>(SIZE);

        for(int j=0; j<SIZE; j++)
            reluMatrix[i][j] = max(0, matrix[i][j]);
        
    }

    return reluMatrix;
}

vector<vector<float>> relu(vector<vector<float>> matrix){
    const int SIZE = matrix.size();
    vector<vector<float>> reluMatrix(SIZE);

    for(int i=0; i<SIZE; i++){
        reluMatrix[i] = vector<float>(SIZE);

        for(int j=0; j<SIZE; j++)
            reluMatrix[i][j] = max(0.0f, matrix[i][j]);
        
    }

    return reluMatrix;
}

vector<vector<float>> tanh(vector<vector<int>> matrix){
    const int SIZE = matrix.size();
    vector<vector<float>> tanhMatrix(SIZE);

    for(int i=0; i<SIZE; i++){
        tanhMatrix[i] = vector<float>(SIZE);

        for(int j=0; j<SIZE; j++)
            tanhMatrix[i][j] = 2.0/(1+exp(-2.0*matrix[i][j])) - 1;
        
    }

    return tanhMatrix;
}


vector<vector<float>> tanh(vector<vector<float>> matrix){
    const int SIZE = matrix.size();
    vector<vector<float>> tanhMatrix(SIZE);

    for(int i=0; i<SIZE; i++){
        tanhMatrix[i] = vector<float>(SIZE);

        for(int j=0; j<SIZE; j++)
            tanhMatrix[i][j] = 2.0/(1+exp(-2.0*matrix[i][j])) - 1;
        
    }

    return tanhMatrix;
}

/*
int main(){
    vector<vector<int>> v{    {1,2,3}, {-1,3,5}, {-23,123,45}};
    vector<vector<float>> computedTANH = tanh(v);
    vector<vector<int>> computedRELU = relu(v);
    
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
}
*/