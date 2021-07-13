#pragma once

#include "ofMain.h"

#include "particleTemplate.h"

class lampFly : public particleTemplate {
    
public:
    vector<ofPoint> get(int num_, float maxSpeed_, ofPoint center_, float maxWidth, float maxHeight_);
    
private:
    vector<ofPoint> particles;
    
    vector<vector<ofPoint>> radians;
    vector<vector<ofPoint>> radianSpeeds;
    int numOfRadians;
};
