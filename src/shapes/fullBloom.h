#pragma once

#include "ofMain.h"

class fullBloom {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_);
    vector<float> getRadiuses(vector<ofPoint> particles_);
    
private:
    vector<float> radiuses;
};
