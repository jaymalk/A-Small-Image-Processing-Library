#include <iostream>
#include <fstream>
#include <iomanip>

#include "../../include/io/AIO.h"
#include "../../include/io/NIO.h"
#include "./measure/watch.h"

#include "../../include/impl/OBM.h"
// #include "../../include/impl/MKM.h"
// #include "../../include/impl/TMM.h"

using namespace std;

double *A, *B, *C;

int main(int argc, char** argv) {
    string name = argv[1];
    watch w1;

    ofstream out("data/"+name+"_step.txt");

    for(int j=0; j<100; j++) {
        cout << j << "\n";
        for(int i=100; i<=800; i+=100) {

            A = convertToArray(inputSquareMatrix("../../files/size_"+to_string(i*i)+".txt"));
            B = convertToArray(inputVector("../../files/size_"+to_string(i)+".txt"));
            C = (double *)malloc(sizeof(double)*i);

            // w1.start();
            // call_multiplication(A, i, B, i, C);
            // w1.stop();
            // out << setprecision(10) <<w1.measure() << " ";
            // w1.reset();

            w1.start();
            call_open_blas(A, i, B, 1, i, C);
            w1.stop();
            out << setprecision(10) <<w1.measure() << " ";
            w1.reset();

            // w1.start();
            // call_mkl(A, i, B, 1, i, C);
            // w1.stop();
            // out << setprecision(10) <<w1.measure() << " ";
            // w1.reset();

            free(A);
            free(B);
            free(C);
        }
        out << "\n";
    }
}
