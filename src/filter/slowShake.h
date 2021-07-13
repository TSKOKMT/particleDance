#pragma once

#include "ofMain.h"

class slowShake {
    
public:
    vector<ofPoint> process(vector<ofPoint> particles_, float amount_, float speed_);
    
private:
    float time;
    vector<ofPoint> particles;
};
