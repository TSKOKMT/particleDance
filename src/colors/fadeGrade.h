#pragma once

#include "ofMain.h"

#include "ofxTskokmtTool.h"

class fadeGrade {
    
public:
    vector<ofColor> get(int num_, vector<float> grades_, float inputMin_ = 0, float inputMax_ = 12, ofColor beginColor_ = ofColor(124, 0, 255), ofColor endColor_ = ofColor(255, 139, 0));
    
private:
    vector<ofColor> colors;
    
    ofxTskokmtTool tool;
};
