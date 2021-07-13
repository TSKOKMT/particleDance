#pragma once

#include "ofMain.h"
#include "ofxTskokmtTool.h"

class macBack {
    
public:
    vector<ofColor> get(int num_);
    
private:
    vector<ofColor> palette;
    vector<ofColor> colors;
    
    ofxTskokmtTool tool;
};
