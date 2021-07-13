#pragma once

#include "ofMain.h"

class dropBox {
 
public:
    vector<ofColor> get(int num_);
    
private:
    vector<ofColor> palette;
    vector<ofColor> colors;
};
