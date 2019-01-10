#include <vector>
#include <cmath>
//#include <iostream>
using namespace std;

vector<float> sigmoid(vector<float> arr){
    const int size = arr.size();
    vector<float> sigmoidVector(size);

    for(int i=0;i<size;i++)
        sigmoidVector[i] = 1.0/(1+exp(-1*arr[i]));

    return sigmoidVector;
}


vector<float> softmax(vector<float> arr){
    const int size = arr.size();
    vector<float> softmaxVector(size);
    float sum=0.0f;

    for(int i=0;i<size;i++){
        softmaxVector[i] = exp(arr[i]);
        sum += softmaxVector[i];
    }

    for(int i=0;i<size;i++)
        softmaxVector[i] /= sum;

    return softmaxVector;
}

/*int main(){
    vector<float> v{1,2,3,4};
    cout<<sigmoid(v)[0]<<endl;
    cout<<softmax(v)[0]<<endl;
}*/