#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"
#include "ofxTskokmtTool.h"

class bezierSnake {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, int stepParInterval_ = 16, bool bFill_ = false);
    
private:
    ofxTskokmtMath math;
    ofxTskokmtTool tool;
};
