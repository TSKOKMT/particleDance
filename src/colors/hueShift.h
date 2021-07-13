#pragma once

#include "ofMain.h"

class hueShift {
    
public:
    vector<ofColor> get(int num_, int startHue_ = 0, int range_ = 64, bool bDark_ = false, bool bBlink_ = false);
    
private:
    vector<ofColor> colors;
    
    vector<float> hueRationsInrange;
    vector<int> saturations;
    vector<int> brightnesses;
};
