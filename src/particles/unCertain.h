#pragma once

#include "ofMain.h"

#include "particleTemplate.h"

#include "ofxTskokmtMath.h"

class unCertain : public particleTemplate {
    
public:
    vector<ofPoint> get(int num_, ofRectangle frame_, vector<ofPolyline> masks_);
    
private:
    ofxTskokmtMath math;
};
