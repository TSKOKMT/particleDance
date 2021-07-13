#pragma once

#include "ofMain.h"

class tadPole {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, float radius_ = 8, float length_ = 16, float lineWidth_ = 3);
    
private:
    vector<ofPoint> lastParticles_;
};
