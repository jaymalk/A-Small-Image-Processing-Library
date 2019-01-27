#include <ctime>
#include <stdexcept>

using namespace std;

#ifndef CLOCK_H
#define CLOCK_H

class watch {
public:
    clock_t begin, end;
    void start() {
        begin = clock();
    }
    void stop() {
        end = clock();
    }
    void reset() {
        begin = 0;
        end = 0;
    }
    double measure() {
            return double(end-begin)/ CLOCKS_PER_SEC;
    }
};

#endif
