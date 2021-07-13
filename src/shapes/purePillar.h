#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"

class purePillar {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, ofRectangle frame_, float size_ = 30, bool bDay_ = true, int colorMode_ = 1);
    
private:
    vector<ofPoint> rotations;
    vector<ofPoint> sizes;
    
    ofCamera camera;
    
    ofxTskokmtMath math;
};
