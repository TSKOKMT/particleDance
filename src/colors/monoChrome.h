#pragma once

#include "ofMain.h"

class monoChrome {
    
public:
    vector<ofColor> get(int num_, ofColor color_ = ofColor(255));
    
private:
    vector<ofColor> colors;
};
