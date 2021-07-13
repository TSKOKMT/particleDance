#include "fullBloom.h"

//--------------------------------------------------------------
void fullBloom::draw(vector<ofPoint> particles_, vector<ofColor> colors_) {
    
    radiuses = getRadiuses(particles_);
    
    //draw
    ofPushStyle();
    for (int i = 0; i < particles_.size(); i++) {
        ofSetColor(colors_[i]);
        ofDrawCircle(particles_[i], radiuses[i]);
    }
    ofPopStyle();
}

//--------------------------------------------------------------
vector<float> fullBloom::getRadiuses(vector<ofPoint> particles_) {
    
    //setup
    if (radiuses.size() != particles_.size()) {
        radiuses.clear();
        for (int i = 0; i < particles_.size(); i++) {
            radiuses.push_back(float());
        }
    }
    
    //update
    if (radiuses.size() != particles_.size()) {
        radiuses.clear();
        for (int i = 0; i < particles_.size(); i++) {
            radiuses.push_back(ofRandom(5, 20));
        }
    }
    radiuses[0] = FLT_MIN;
    for (int i = 1; i < particles_.size(); i++) {
        int radius = INT_MAX;
        for (int j = 0; j < i; j++) {
            if (particles_[i].distance(particles_[j]) - radiuses[j] < radius) radius = ofClamp(particles_[i].distance(particles_[j]) - radiuses[j], 0, INT_MAX);
        }
        //radiuses[i] += (radius - radiuses[i]) * 0.9;
        radiuses[i] = radius;
        radiuses[i] -= min(ofGetWidth(), ofGetHeight()) / 512.;
        if (radiuses[i] < 0) radiuses[i] = 0;
    }
    
    return radiuses;
}
