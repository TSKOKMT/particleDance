#pragma once

#include "ofMain.h"

class feebleVibe {
    
public:
    vector<ofPoint> process(vector<ofPoint> particles_, float amount_);
    
private:
    float time;
    vector<ofPoint> particles;
};
