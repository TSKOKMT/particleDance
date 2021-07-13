#pragma once

#include "ofMain.h"

#include "particleTemplate.h"

class onLine : public particleTemplate {
    
public:
    vector<ofPoint> get(int num_, ofRectangle frame_, vector<ofPolyline> polylines_);
    
private:
};
