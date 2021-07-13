#pragma once

#include "ofMain.h"

class dotSpot {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, float minRadius_ = 4, float maxRadius_ = 16, bool bRandomRoate_ = false);
    
private:
    vector<float> radiuses;
    
    ofSoundPlayer sound;
};
