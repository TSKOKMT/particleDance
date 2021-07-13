#pragma once

#include "ofMain.h"
#include "ofxTskokmtGraphic.h"
#include "ofxTskokmtMotion.h"

class paperTape {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, int length_ = 30);
    
private:
    vector<vector<ofPoint>> logs;
    vector<ofPoint> previousParticles;
};
