#pragma once

#include "ofMain.h"

class streamFlow {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, int length_ = 16, int fadeMode_ = 2, int step_ = 1);
    
private:
    ofVbo vbo;
    vector<vector<ofPoint>> pastParticles;
};
