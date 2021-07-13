#pragma once

#include "ofMain.h"

#include "particleTemplate.h"

#include "ofxTskokmtMath.h"

class energySource : public particleTemplate {
    
public:
    vector<ofPoint> get(int num_, ofRectangle frame_, float activeRadius_ = 30);
    
    void createTouch(ofPoint position_);
    
private:
    vector<ofPoint> touches;
    vector<ofPoint> previousTouches;
    vector<bool> bActives;
    vector<ofPoint> centers;
    vector<int> indexes;
    
    ofxTskokmtMath math;
};
