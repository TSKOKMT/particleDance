#pragma once

#include "ofMain.h"
#include "ofxVoronoi.h"

#include "ofxTskokmtMath.h"

class voronoiCell {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, ofRectangle drawRect_, int mode_ = 0);
    
private:
    ofxVoronoi voronoi;
    vector<ofxVoronoiCell> cells;
    
    ofxTskokmtMath math;
};
