#pragma once

#include "ofMain.h"

#include "particleTemplate.h"

#include "ofxTskokmtMath.h"

class leapFrog : public particleTemplate {
    
public:
    vector<ofPoint> get(int num_, ofRectangle frame_, float &time_, float minInterval_ = 1, float maxInterval_ = 2);
    
    void createIsland(ofPoint island_);
    void createIslands(vector<ofPoint> islands_);
    
private:
    vector<ofPoint> islands;
    
    vector<float> intervals;
    vector<vector<ofPoint>> groups;
    
    ofxTskokmtMath math;
};
