#pragma once

#include "ofMain.h"

#include "particleTemplate.h"

class traceTrack : public particleTemplate {
    
public:
    vector<ofPoint> get(int num_, ofRectangle frame_, vector<ofPolyline> polylines_, float minSpeed_ = 1, float maxSpeed_ = 2);
    
private:
    vector<float> trackSpeeds;
    vector<float> percents;
};
