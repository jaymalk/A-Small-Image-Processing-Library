#include <iostream>
#include <vector>

#include "../../func/pool.h"

#ifndef L2V
#define L2V

vector<vector<vector<float>>> pool_layer_l2(vector<vector<vector<float>>>& in_chnl_l2) {
    for(int i=0; i<in_chnl_l2.size(); i++) {
        in_chnl_l2[i] = maxPool(in_chnl_l2[i]);
    }
    return in_chnl_l2;
}

#endif
