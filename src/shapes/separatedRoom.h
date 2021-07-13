#pragma once

#include "ofMain.h"

#include "ofxTskokmtMath.h"
#include "ofxTskokmtTool.h"

class separatedRoom {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, ofRectangle frame_, float lineWidth_ = 2, int mode_ = 0);
    
private:
    vector<ofRectangle> rects;
    vector<bool> bVerticals;
    
    ofxTskokmtMath math;
    ofxTskokmtTool tool;
};
