#include <iostream>
#include <fstream>

#include "VectorToArray.h"
#include "../Subtask 1/NIO.h"
#include "stopwatch.h"
#include "OBM.h"

using namespace std;

double *A, *B, *C;

int main() {
    ofstream out("Data/open_blas.txt");
    out << "Time\n\n";

    for(int i=3; i<=400; i++) {
        A = convertToArray(inputSquareMatrix("files/size_"+to_string(i*i)+".txt"));
        B =  convertToArray(inputVector("files/size_"+to_string(i)+".txt"));
        C = convertToArray(vector<float>(i, 0));

        cout << i << "\n";

        stopwatch sw;
        sw.tick();

        for(int j=0; j<100; j++)
            call_open_blas(A, i, B, 1, i, C);

        sw.tock();
            out << sw.report_ms() << "\n";
    }
}
