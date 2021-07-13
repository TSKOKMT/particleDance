#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

class superSmooth {
    
public:
    vector<ofPoint> process(vector<ofPoint> particles_, int mean_ = 4, float ease_ = .1);
    
private:
    ofxTskokmtMath math;
};
