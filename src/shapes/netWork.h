#pragma once

#include "ofMain.h"

class netWork {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, int amount_ = 3);
    
private:
    vector<vector<int>> indexes;
};
