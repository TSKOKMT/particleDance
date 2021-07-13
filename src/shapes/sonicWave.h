#pragma once

#include "ofMain.h"
#include "ofxTskokmtGraphic.h"
#include "ofxTskokmtMotion.h"

class sonicWave {
    
public:
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, float interval_ = .1, float endRadius_ = 1080, int spendTerm_ = 5, int mode_ = 0);
    void draw(vector<ofPoint> particles_, vector<ofColor> colors_, float interval_, vector<float> endRadiuses_, int spendTerm_, int mode_ = 0);
    
private:
    class rippleParticle {
    public:
        void draw(ofPoint position_, ofColor color_, float interval_, float endRadius_, int spendTerm_, int mode_);
    private:
        float time;
        float previousTime;
        vector<ofPoint> positions;
        vector<float> radiuses;
        vector<float> endRadiuses;
        vector<ofxTskokmtMotion> motions;
    };
    vector<rippleParticle> rippleParticles;
    vector<ofPoint> previousParticles;
    vector<float> speeds;
};
