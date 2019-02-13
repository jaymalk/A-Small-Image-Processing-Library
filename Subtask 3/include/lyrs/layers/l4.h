#include <iostream>
#include <vector>

#include "../../func/pool.h"

#ifndef L4V
#define L4V

vector<vector<vector<float>>> pool_layer_l4(vector<vector<vector<float>>>& in_chnl_l4) {
    for(int i=0; i<in_chnl_l4.size(); i++) {
        in_chnl_l4[i] = maxPool(in_chnl_l4[i]);
    }
    return in_chnl_l4;
}

#endif
