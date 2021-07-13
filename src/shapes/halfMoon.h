#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

class halfMoon {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, float minRadius_ = 30, float maxRadius_ = 480);
    
private:
    vector<ofPoint> lastParticles;
    vector<float> radiuses;
    
    ofxTskokmtMath math;
};
