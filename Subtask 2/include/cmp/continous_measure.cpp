#include <iostream>
#include <fstream>
#include <iomanip>

#include "../../include/io/AIO.h"
#include "../../include/io/NIO.h"
#include "./measure/watch.h"

//#include "../../include/impl/OBM.h"
// #include "../../include/impl/MKM.h"
#include "../../include/impl/TMM.h"

using namespace std;

double *A, *B, *C;

int main() {
    ofstream out("data/ur.txt");
    watch w1;

    for(int i=3; i<=800; i++) {
        A = convertToArray(inputSquareMatrix("../../files/size_"+to_string(i*i)+".txt"));
        B = convertToArray(inputVector("../../files/size_"+to_string(i)+".txt"));
        C = (double *)malloc(sizeof(double)*i);

        cout << i << "\n";

        w1.start();
        for(int j=0; j<10; j++)
            call_multiplication(A, i, B, i, C);
        w1.stop();
        out << i << " " << setprecision(10) <<w1.measure()*100 << "\n";
        w1.reset();

        // w1.start();
        // for(int j=0; j<100; j++)
        //     call_open_blas(A, i, B, 1, i, C);
        // w1.stop();
        // out << setprecision(10) <<w1.measure() << "\n";
        // w1.reset();

        // w1.start();
        // for(int j=0; j<100; j++)
        //     call_mkl(A, i, B, 1, i, C);
        // w1.stop();
        // out << setprecision(10) <<w1.measure() << "\n";
        // w1.reset();
    }
}
