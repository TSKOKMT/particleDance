#pragma once

#include "ofMain.h"

#include "particleTemplate.h"

#include "ofxTskokmtMath.h"

class followYou : public particleTemplate {
    
public:
    vector<ofPoint> get(int num_, ofRectangle frame_, ofPoint size_, int meanNum_ = 4, float easeAmount_ = .1);
    
    void createPosition(ofPoint position_, float weight_);
    
private:
    vector<ofPoint> positions;
    vector<ofPoint> previousPositions;
    vector<float> weights;
    vector<int> indexes;
    vector<ofxTskokmtMath> mathes;
};
