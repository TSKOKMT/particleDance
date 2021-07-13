#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

class particleTemplate {
    
public:
    void setup(int &num_, ofRectangle frame_);
    void update();
    
    vector<ofPoint> particles;
    vector<ofPoint> previousParticles;
    vector<ofPoint> differences;
    vector<float> directions;
    vector<float> speeds;
    
private:
    ofxTskokmtMath math;
};

