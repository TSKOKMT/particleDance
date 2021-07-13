#pragma once

#include "ofMain.h"

#include "particleTemplate.h"

#include "ofxLiquidFun.h"
#include "ofxTskokmtMath.h"

class waterMolecule : public particleTemplate {
    
public:
    vector<ofPoint> get(int num_, ofRectangle frame_);
    
    void createTornado(ofPoint eye_, float amount_, bool bClockwise_ = false);

private:
    //liquidFun
    ofxBox2d box2d;
    ofxBox2dParticleSystem particleSystem;
    bool bSetupBox2d = false;
    vector<ofPoint> eyes;
    vector<ofPoint> previousEyes;
    vector<float> amounts;
    vector<bool> bClockwises;
    vector<int> indexes;
    
    //math
    ofxTskokmtMath math;
};
