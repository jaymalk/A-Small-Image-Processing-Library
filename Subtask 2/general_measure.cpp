#include <iostream>
#include <fstream>

#include "./include/io/AIO.h"
#include "./include/io/NIO.h"
#include "./include/measure/stopwatch.h"

 //#include "./include/impl/OBM.h"
// #include "./include/impl/MKM.h"
#include "./include/impl/TMM.h"

using namespace std;

double *A, *B, *C;

int main() {
    ofstream out("Data/our.txt");
    out << "Time\n\n";

    stopwatch sw;

    for(int i=3; i<=800; i++) {
        A = convertToArray(inputSquareMatrix("files/size_"+to_string(i*i)+".txt"));
        B = convertToArray(inputVector("files/size_"+to_string(i)+".txt"));
        C = (double *)malloc(sizeof(double)*i);

        cout << i << "\n";

        sw.reset();
        sw.tick();

        for(int j=0; j<100; j++)
            call_multiplication(A, i, B, i, C);

        sw.tock();
        //     out << sw.report_ms() << " ";
        //
        // sw.reset();
        // sw.tick();
        //
        // for(int j=0; j<100; j++)
        //     call_open_blas(A, i, B, 1, i, C);
        //
        // sw.tock();
        //     out << sw.report_ms() << " ";
        //
        // sw.reset();
        // sw.tick();
        //
        // for(int j=0; j<100; j++)
        //     call_open_blas(A, i, B, 1, i, C);
        //
        // sw.tock();
            out << sw.report_ms() << "\n";
    }
}
