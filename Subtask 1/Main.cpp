/* Main program.
    Take all inputs from command line.
    Take actions accordingly
    */
#include <iostream>
#include <fstream>
#include <cstring>

#include "activation.h"
#include "pool.h"
#include "convolution.h"
#include "NIO.h"
#include "IO.h"


using namespace std;

int main(int argc, char const *argv[]) {
    try {
        if(argc == 1)
            throw runtime_error("No function. Please enter a function.\n");
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        if(argv[1][0] == 'c')
        /* conv or cross*/
        {
            if(argv[1][1] == 'o')
            /* conv */
            {
                if(!strcmp("conv", argv[1])) {
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


                else if(!strcmp("conv_pad", argv[1])) {
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


                else if(!strcmp("conv_mult", argv[1])) {
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
                        printMatrix(convolutionByMultiplication(kernel, matrix, true));
                    }
                    else
                    /* Output in File*/
                    {
                        try {
                            ofstream out(argv[4]);
                            writeMatrix(convolutionByMultiplication(kernel, matrix, true), out);
                        }
                        catch(...) {
                            throw runtime_error("Error in writing. Please check.\n");
                        }
                    }
                }


                else if(!strcmp("conv_mult_pad", argv[1])) {
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
                        printMatrix(convolutionByMultiplication(kernel, matrix, true, true));
                    }
                    else
                    /* Output in File*/
                    {
                        try {
                            ofstream out(argv[4]);
                            writeMatrix(convolutionByMultiplication(kernel, matrix, true, true), out);
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
                if(!strcmp("cross", argv[1])) {
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


                else if(!strcmp("cross_pad", argv[1])) {
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


                else if(!strcmp("cross_mult", argv[1])) {
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
                        printMatrix(convolutionByMultiplication(kernel, matrix, false));
                    }
                    else
                    /* Output in File*/
                    {
                        try {
                            ofstream out(argv[4]);
                            writeMatrix(convolutionByMultiplication(kernel, matrix, false), out);
                        }
                        catch(...) {
                            throw runtime_error("Error in writing. Please check.\n");
                        }
                    }
                }


                else if(!strcmp("cross_mult_pad", argv[1])) {
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
                        printMatrix(convolutionByMultiplication(kernel, matrix, false, true));
                    }
                    else
                    /* Output in File*/
                    {
                        try {
                            ofstream out(argv[4]);
                            writeMatrix(convolutionByMultiplication(kernel, matrix, false, true), out);
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
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else if(argv[1][0] == 'r')
        /*relu*/
        {
            if(strcmp("relu", argv[1]))
                throw runtime_error("Invalid Function. Did you mean 'relu'?\n");
            if(argc < 4 || argc > 5)
                throw runtime_error("Command statement wrong/incomplete. Please see documentation.\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputMatrix(argv[2], stoi(argv[3]));
            }
            catch(const runtime_error& e) {
                throw e;
            }
            catch(...) {
                throw runtime_error("Error with matrix file or num_rows. Please check.\n");
            }
            if(argc == 4)
            /* Output on command line*/
            {
                printMatrix(relu(matrix));
            }
            else
            /* Output in File*/
            {
                try {
                    ofstream out(argv[4]);
                    writeMatrix(relu(matrix), out);
                }
                catch(...) {
                    throw runtime_error("Error in writing. Please check.\n");
                }
            }

        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else if(argv[1][0] == 't')
        /*tanh*/
        {
            if(strcmp("tanh", argv[1]))
                throw runtime_error("Invalid Function. Did you mean 'tanh'?\n");
            if(argc < 4 || argc > 5)
                throw runtime_error("Command statement wrong/incomplete. Please see documentation.\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputMatrix(argv[2], stoi(argv[3]));
            }
            catch(const runtime_error& e) {
                throw e;
            }
            if(argc == 4)
            /* Output on command line*/
            {
                printMatrix(tanh(matrix));
            }
            else
            /* Output in File*/
            {
                try {
                    ofstream out(argv[4]);
                    writeMatrix(tanh(matrix), out);
                }
                catch(...) {
                    throw runtime_error("Error in writing. Please check.\n");
                }
            }
        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else if(argv[1][0] == 's')
        /*softmax or sigmoid*/
        {
            if(argv[1][1] == 'o')
            /* softmax */
            {
                if(strcmp("softmax", argv[1]))
                    throw runtime_error("Invalid Function. Did you mean 'softmax'?\n");
                if(argc < 3 || argc > 4)
                    throw runtime_error("Command statement wrong/incomplete. Please see documentation.\n");
                vector<float> vectr{};
                try {
                    vectr = inputVector(argv[2]);
                }
                catch(const runtime_error& e) {
                    throw e;
                }
                catch(...) {
                    throw runtime_error("Error with vector file. Please check.\n");
                }
                if(argc == 3)
                /* Output on command line*/
                {
                    writeVector(softmax(vectr));
                }
                else
                /* Output in File*/
                {
                    try {
                        ofstream out(argv[3]);
                        writeVector(softmax(vectr), out);
                    }
                    catch(...) {
                        throw runtime_error("Error in writing. Please check.\n");
                    }
                }
            }
            else if(argv[1][1] == 'i')
            /* sigmoid */
            {
                if(strcmp("sigmoid", argv[1]))
                    throw runtime_error("Invalid Function. Did you mean 'sigmoid'?\n");
                if(argc < 3 || argc > 4)
                    throw runtime_error("Command statement wrong/incomplete. Please see documentation.\n");
                vector<float> vectr{};
                try {
                    vectr = inputVector(argv[2]);
                }
                catch(const runtime_error& e) {
                    throw e;
                }
                catch(...) {
                    throw runtime_error("Error with vector file. Please check.\n");
                }
                if(argc == 3)
                /* Output on command line*/
                {
                    writeVector(sigmoid(vectr));
                }
                else
                /* Output in File*/
                {
                    try {
                        ofstream out(argv[3]);
                        writeVector(sigmoid(vectr), out);
                    }
                    catch(...) {
                        throw runtime_error("Error in writing. Please check.\n");
                    }
                }
            }
            else
                throw runtime_error("Invalid Function. Did you mean 'sigmoid' or 'softmax'?\n");
        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else if(argv[1][0] == 'm')
        /* max_pool */
        {
            if(strcmp("max_pool", argv[1]))
                throw runtime_error("Invalid Function. Did you mean 'max_pool'?\n");
            if(argc < 5 || argc > 6)
                throw runtime_error("Command statement wrong/incomplete. Please see documentation.\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputSquareMatrix(argv[2]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            if(argc == 5)
            /* Output on command line */
            {
                try {
                    int filterSize = stoi(argv[3]);
                    int stride = stoi(argv[4]);
                    printMatrix(maxPool(matrix, filterSize, stride));
                }
                catch(...) {
                    throw runtime_error("Error in writing (probably stride or filter). Please check.\n");
                }
            }
            else
            /* Output in a file */
            {
                try {
                    ofstream out(argv[3]);
                    int filterSize = stoi(argv[4]);
                    int stride = stoi(argv[5]);
                    writeMatrix(maxPool(matrix, filterSize, stride), out);
                }
                catch(...) {
                    throw runtime_error("Error in writing (probably stride or filter). Please check.\n");
                }
            }
        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else if(argv[1][0] == 'a')
        /* avg_pool */
        {
            if(strcmp("avg_pool", argv[1]))
                throw runtime_error("Invalid Function. Did you mean 'avg_pool'?\n");
            if(argc < 5 || argc > 6)
                throw runtime_error("Command statement wrong/incomplete. Please see documentation.\n");
            vector<vector<float>> matrix{};
            try {
                matrix = inputSquareMatrix(argv[2]);
            }
            catch(const runtime_error& e) {
                throw e;
            }
            if(argc == 5)
            /* Output on command line */
            {
                try {
                    int filterSize = stoi(argv[3]);
                    int stride = stoi(argv[4]);
                    printMatrix(avgPool(matrix, filterSize, stride));
                }
                catch(...) {
                    throw runtime_error("Error in writing (probably stride or filter). Please check.\n");
                }
            }
            else
            /* Output in a file */
            {
                try {
                    ofstream out(argv[3]);
                    int filterSize = stoi(argv[4]);
                    int stride = stoi(argv[5]);
                    writeMatrix(avgPool(matrix, filterSize, stride), out);
                }
                catch(...) {
                    throw runtime_error("Error in writing (probably stride or filter). Please check.\n");
                }
            }
        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else if (argv[1][0] == 'v')
        /* view or view_square */
        {
            if(!strcmp("view", argv[1]))
            /* view */
            {
                vector<vector<float>> matrix{};
                try {
                    matrix = inputMatrix(argv[2], stoi(argv[3]));
                }
                catch(const runtime_error& e) {
                    throw e;
                }
                printMatrix(matrix);
            }
            else if(!strcmp("view_square", argv[1]))
            /* view_square */
            {
                vector<vector<float>> matrix{};
                try {
                    matrix = inputSquareMatrix(argv[2]);
                }
                catch(const runtime_error& e) {
                    throw e;
                }
                printMatrix(matrix);
            }
            else
                throw runtime_error("Invalid Function. Did you mean 'view' or 'view_square'?\n");
        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else
            throw runtime_error("Invalid Function\n");
    }
    catch(const exception& e) {
        cout << e.what();
    }
    return 0;
}
