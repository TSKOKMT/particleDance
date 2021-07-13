#pragma once

#include "ofMain.h"

#include "particleTemplate.h"

class perfectBound : public particleTemplate {
    
public:
    vector<ofPoint> get(int num_, ofRectangle frame_, float minSpeed_ = 0, float maxSpeed_ = 4, float movement_ = 1);
    
private:
    vector<float> directions2;
    vector<float> speeds2;
};
