#pragma once

#include "ofMain.h"

#include "particleTemplate.h"

#include "ofxBox2d.h"
#include "ofxTskokmtTool.h"

class grayHole : public particleTemplate {
    
public:
    vector<ofPoint> get(int num_, ofRectangle frame_, float minRadius_ = 30, float maxRadius_ = 90, float targetObjectSize_ = 8);
    
    void createForce(ofPoint position_, float amount_);
    void createForces(vector<ofPoint> positions_, vector<float> amounts_);
    
private:
    ofxBox2d box2d;
    bool bSetupBox2d = false;
    vector<ofPtr<ofxBox2dRect>> box2dRects;
    vector<ofPoint> forcePositions;
    vector<float> forceAmounts;
    vector<ofPoint> previousForcePositions;
    vector<int> indexes;
    vector<float> radiuses;
    
    ofxTskokmtTool tool;
};
