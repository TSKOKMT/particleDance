#pragma once

#include "ofMain.h"
#include "ofxTskokmtGraphic.h"

class swimmyFish {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, float minRadius_ = 4, float maxRadius_ = 8, int minLength_ = 8, int maxLength_ = 16);
    
private:
    vector<float> radiuses;
    vector<ofxTskokmtGraphic> graphics;
    vector<int> lengthes;
};
