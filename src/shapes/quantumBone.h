#pragma once

#include "ofMain.h"

class quantumBone {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, int length_ = 32, int mode_ = 1, int step_ = 1);
    
private:
    ofVbo vbo;
    vector<vector<ofPoint>> pastParticles;
};
