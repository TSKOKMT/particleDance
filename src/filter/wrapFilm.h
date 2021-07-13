#pragma once

#include "ofMain.h"

#include "ofxConvexHull.h"

class wrapFilm {
    
public:
    vector<ofPoint> process(vector<ofPoint> particles_, float minJoinDist_ = 60.);
    
private:
    ofxConvexHull convexHull;
};
