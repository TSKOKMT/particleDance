#pragma once

#include "ofMain.h"

class bookShelf {
 
public:
    vector<ofColor> get(int num_);
    
private:
    vector<ofColor> palette;
    vector<ofColor> colors;
};
