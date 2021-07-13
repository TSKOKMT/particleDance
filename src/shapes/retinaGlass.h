#pragma once

#include "ofMain.h"

class retinaGlass {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, ofRectangle frame_, float minWidth_ = .01, float maxWidth_ = .1, bool bVertical_ = false, bool bDay_ = false);
    
private:
    vector<float> widthSeeds;
};
