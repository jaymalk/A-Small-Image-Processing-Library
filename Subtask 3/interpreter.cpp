/*
    CREATED BY RAJAT JAISWAL AND RAJBIR MALIK
    INTERPRETER WHICH SUPPORTS MANY IMAGE PROCESSING FEATURES
    CREATED DURING THE COURSE COP290 (UNDER PROF. RIJUREKHA SEN)
*/

#include <iostream>
#include <fstream>
#include <cstring>

#include "include/func/activation.h"
#include "include/func/pool.h"
#include "include/func/conv/handle.h"
#include "include/lyrs/lenet.h"

#include "include/io/NIO.h"
#include "include/io/IO.h"

using namespace std;

void call(int argc, vector<string> argv) {
    try {
        if(argc <= 1)
            throw runtime_error("No function. Please enter a function.\n");
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        if(argv[1][0] == 'c')
        /* conv or cross*/
        {
            convolution_handle(argc, argv);
        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else if(argv[1][0] == 'r')
        /*relu*/
        {
            if(!("relu" == argv[1]))
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
            if(!("tanh" == argv[1]))
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
                if(!("softmax" == argv[1]))
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
                    printVector(softmax(vectr));
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
                if(!("sigmoid" == argv[1]))
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
                    printVector(sigmoid(vectr));
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
            if(!("max_pool" == argv[1]))
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
                    ofstream out(argv[5]);
                    int filterSize = stoi(argv[3]);
                    int stride = stoi(argv[4]);
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
            if(!("avg_pool" == argv[1]))
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
                    ofstream out(argv[5]);
                    int filterSize = stoi(argv[3]);
                    int stride = stoi(argv[4]);
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
            if(("view" == argv[1]))
            /* view */
            {
                vector<vector<float>> matrix{};
                try {
                    if(argc != 4)
                        throw runtime_error("Command not correct.\n");

                    matrix = inputMatrix(argv[2], stoi(argv[3]));
                }
                catch(const runtime_error& e) {
                    throw e;
                }
                catch(...) {
                    throw runtime_error("Command not correct.\n");
                }
                printMatrix(matrix);
            }
            else if(("view_square" == argv[1]))
            /* view_square */
            {
                vector<vector<float>> matrix{};
                try {
                    if(argc != 3)
                        throw runtime_error("Command not correct.\n");
                    matrix = inputSquareMatrix(argv[2]);
                }
                catch(const runtime_error& e) {
                    throw e;
                }
                catch(...) {
                    throw runtime_error("Command not correct.\n");
                }
                printMatrix(matrix);
            }
            else
                throw runtime_error("Invalid Function. Did you mean 'view' or 'view_square'?\n");
        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else if (argv[1][0] == 'd')
        /* digit_rec && digit_prob */
        {
            if("digit_rec" == argv[1]) {
                try {
                    if(argc != 3)
                        throw runtime_error("Command not correct. Please see documentation.\n");
                    implement_lenet(argv[2], 1);
                }
                catch(const runtime_error& e) {
                    throw e;
                }
                catch(...) {
                    throw runtime_error("Command not correct.\n");
                }
            }
            else if("digit_prob" == argv[1]) {
                try {
                    if(argc != 3)
                        throw runtime_error("Command not correct. Please see documentation.\n");
                    implement_lenet(argv[2], 0);
                }
                catch(const runtime_error& e) {
                    throw e;
                }
                catch(...) {
                    throw runtime_error("Command not correct.\n");
                }
            }
            else
                throw runtime_error("Invalid Function. Did you mean 'digit_rec' or 'digit_prob'?\n");
        }
        /*-------------------------------------------------------------
        -------------------------------------------------------------*/
        else
            throw runtime_error("Invalid Function\n");
    }
    catch(const exception& e) {
        cout << e.what();
    }
}

int main(int argc, char const *argv[]) {
    string line, word;
    vector<string> history{};
    while(true) {
        cout << "\n> ";
        getline(cin, line);
        if(line == "")
            continue;
        istringstream a(line);
        a >> word;
        if(word == "exit")
        /* exit */
            return 0;
        else if(word == "clear")
        /* clear console */
        {
            cout << "\033[H\033[J";
            continue;
        }
        else if(word == "...")
        /* call history */
        {
            a >> word;
            if("..." != word)
                history.push_back(word);
            call(history.size(), history);
            continue;
        }
        /* call */
        vector<string> argv{"./a.out", word};
        while(a >> word) {
            argv.push_back(word);
        }
        history = argv;
        cout << "\n";
        try {
            call(argv.size(), argv);
        }
        catch(...) {
            cout << "Unknown exception. (IN LOOP)";
        }
    }
    return 0;
}
