#pragma once

#include "ofMain.h"

#include "ofxTskokmtGraphic.h"
#include "ofxVboParticles.h"

class pixieSmoke {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, float spreadSpeed_ = 2);
    
private:
    ofxVboParticles *vboPartciles;
    bool bNew = false;
};
