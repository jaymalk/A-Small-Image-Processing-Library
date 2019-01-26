// LIBRARY FOR HANDELING CONVOLUTION IN INTERPRETER

#include <iostream>
#include <vector>
#include <string>

#include "convolution_threaded.h"
#include "../../io/NIO.h"
#include "../../io/IO.h"
#include "../../io/AIO.h"

using namespace std;

#ifndef CONVOLUTION_HANDLE
#define CONVOLUTION_HANDLE

void convolution_handle(int argc, vector<string> argv) {
    if(argv[1][1] == 'o')
    /* conv */
    {
        if("conv" == argv[1]) {
            if(argc < 4 || argc > 5)
                throw runtime_error("Command statement wrong/incomplete. Please see documentation.\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputSquareMatrix(argv[2]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            vector<vector<float>> kernel{};
            try {
                kernel = inputSquareMatrix(argv[3]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            if(kernel.size() > matrix.size())
                throw runtime_error("Invalid: Kernel size is greater than matrix size.\n");
            if(argc == 4)
            /* Output on command line*/
            {
                printMatrix(directConvolution(kernel, matrix, true));
            }
            else
            /* Output in File*/
            {
                try {
                    ofstream out(argv[4]);
                    writeMatrix(directConvolution(kernel, matrix, true), out);
                }
                catch(...) {
                    throw runtime_error("Error in writing. Please check.\n");
                }
            }

        }


        else if(("conv_pad" == argv[1])) {
            if(argc < 4 || argc > 5)
                throw runtime_error("Command statement wrong/incomplete. Please see documentation.\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputSquareMatrix(argv[2]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            vector<vector<float>> kernel{};
            try {
                kernel = inputSquareMatrix(argv[3]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            if(kernel.size() > matrix.size())
                throw runtime_error("Invalid: Kernel size is greater than matrix size.\n");
            if(argc == 4)
            /* Output on command line*/
            {
                printMatrix(directConvolution(kernel, matrix, true, true));
            }
            else
            /* Output in File*/
            {
                try {
                    ofstream out(argv[4]);
                    writeMatrix(directConvolution(kernel, matrix, true, true), out);
                }
                catch(...) {
                    throw runtime_error("Error in writing. Please check.\n");
                }
            }
        }


        else if(("conv_mult" == argv[1])) {
            if(argc < 4 || argc > 5)
                throw runtime_error("Command statement wrong/incomplete. Please see documentation.\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputSquareMatrix(argv[2]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            vector<vector<float>> kernel{};
            try {
                kernel = inputSquareMatrix(argv[3]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            if(kernel.size() > matrix.size())
                throw runtime_error("Invalid: Kernel size is greater than matrix size.\n");
            if(argc == 4)
            /* Output on command line*/
            {
                double *d = convolutionByMultiplication(kernel, matrix, true);
                printSquareArray(d, matrix.size()-kernel.size()+1);
                free(d);
            }
            else
            /* Output in File*/
            {
                try {
                    ofstream out(argv[4]);
                    double *d = convolutionByMultiplication(kernel, matrix, true);
                    writeSquareArray(d, matrix.size()-kernel.size()+1, out);
                    free(d);
                }
                catch(...) {
                    throw runtime_error("Error in writing. Please check.\n");
                }
            }
        }


        else if(("conv_mult_pad" == argv[1])) {
            if(argc < 4 || argc > 5)
                throw runtime_error("Command statement wrong/incomplete. Please see documentation.\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputSquareMatrix(argv[2]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            vector<vector<float>> kernel{};
            try {
                kernel = inputSquareMatrix(argv[3]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            if(kernel.size() > matrix.size())
                throw runtime_error("Invalid: Kernel size is greater than matrix size.\n");
            if(argc == 4)
            /* Output on command line*/
            {
                double *d = convolutionByMultiplication(kernel, matrix, true, true);
                printSquareArray(d, matrix.size());
                free(d);
            }
            else
            /* Output in File*/
            {
                try {
                    ofstream out(argv[4]);
                    double *d = convolutionByMultiplication(kernel, matrix, true, true);
                    writeSquareArray(d, matrix.size(), out);
                    free(d);
                }
                catch(...) {
                    throw runtime_error("Error in writing. Please check.\n");
                }
            }
        }


        else
            throw runtime_error("Invalid Function. Did you mean 'conv'?\n");
    }
    else if(argv[1][1] == 'r')
    /* cross */
    {
        if(("cross" == argv[1])) {
            if(argc < 4 || argc > 5)
                throw runtime_error("Command statement wrong/incomplete. Please see documentation.\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputSquareMatrix(argv[2]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            vector<vector<float>> kernel{};
            try {
                kernel = inputSquareMatrix(argv[3]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            if(kernel.size() > matrix.size())
                throw runtime_error("Invalid: Kernel size is greater than matrix size.\n");
            if(argc == 4)
            /* Output on command line*/
            {
                printMatrix(directConvolution(kernel, matrix, false));
            }
            else
            /* Output in File*/
            {
                try {
                    ofstream out(argv[4]);
                    writeMatrix(directConvolution(kernel, matrix, false), out);
                }
                catch(...) {
                    throw runtime_error("Error in writing. Please check.\n");
                }
            }

        }


        else if(("cross_pad" == argv[1])) {
            if(argc < 4 || argc > 5)
                throw runtime_error("Command statement wrong/incomplete. Please see documentation.\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputSquareMatrix(argv[2]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            vector<vector<float>> kernel{};
            try {
                kernel = inputSquareMatrix(argv[3]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            if(kernel.size() > matrix.size())
                throw runtime_error("Invalid: Kernel size is greater than matrix size.\n");
            if(argc == 4)
            /* Output on command line*/
            {
                printMatrix(directConvolution(kernel, matrix, false, true));
            }
            else
            /* Output in File*/
            {
                try {
                    ofstream out(argv[4]);
                    writeMatrix(directConvolution(kernel, matrix, false, true), out);
                }
                catch(...) {
                    throw runtime_error("Error in writing. Please check.\n");
                }
            }
        }


        else if(("cross_mult" == argv[1])) {
            if(argc < 4 || argc > 5)
                throw runtime_error("Command statement wrong/incomplete. Please see documentation.\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputSquareMatrix(argv[2]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            vector<vector<float>> kernel{};
            try {
                kernel = inputSquareMatrix(argv[3]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            if(kernel.size() > matrix.size())
                throw runtime_error("Invalid: Kernel size is greater than matrix size.\n");
            if(argc == 4)
            /* Output on command line*/
            {
                double *d = convolutionByMultiplication(kernel, matrix, false);
                printSquareArray(d, matrix.size()-kernel.size()+1);
                free(d);
            }
            else
            /* Output in File*/
            {
                try {
                    ofstream out(argv[4]);
                    double *d = convolutionByMultiplication(kernel, matrix, false);
                    writeSquareArray(d, matrix.size()-kernel.size()+1, out);
                    free(d);
                }
                catch(...) {
                    throw runtime_error("Error in writing. Please check.\n");
                }
            }
        }


        else if(("cross_mult_pad" == argv[1])) {
            if(argc < 4 || argc > 5)
                throw runtime_error("Command statement wrong/incomplete. Please see documentation.\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputSquareMatrix(argv[2]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            vector<vector<float>> kernel{};
            try {
                kernel = inputSquareMatrix(argv[3]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            if(kernel.size() > matrix.size())
                throw runtime_error("Invalid: Kernel size is greater than matrix size.\n");
            if(argc == 4)
            /* Output on command line*/
            {
                double *d = convolutionByMultiplication(kernel, matrix, false, true);
                printSquareArray(d, matrix.size());
                free(d);
            }
            else
            /* Output in File*/
            {
                try {
                    ofstream out(argv[4]);
                    double *d = convolutionByMultiplication(kernel, matrix, false, true);
                    writeSquareArray(d, matrix.size(), out);
                    free(d);
                }
                catch(...) {
                    throw runtime_error("Error in writing. Please check.\n");
                }
            }
        }


        else
            throw runtime_error("Invalid Function. Did you mean 'conv'?\n");
    }
    else
        throw runtime_error("Invalid Function. Did you mean 'conv' or 'cross'?\n");
}

#endif
