#pragma once

#include "ofMain.h"

#include "particleTemplate.h"

#include "ofxBox2d.h"

class upsideDown : public particleTemplate {
    
public:
    vector<ofPoint> get(int num_, ofRectangle frame_, float &time_, float interval_ = 2, float gravity_ = 100, float targetObjectSize_ = 8);
    
    void createEdges(vector<ofPolyline> polylines_);
    
private:
    ofxBox2d box2d;
    vector<ofPtr<ofxBox2dCircle>> box2dCircles;
    vector<ofPtr<ofxBox2dEdge>> edges;
    bool bSetupBox2d = false;
};
