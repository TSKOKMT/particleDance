#include "tadPole.h"

//--------------------------------------------------------------
void tadPole::draw(vector<ofPoint> particles_, vector<ofColor> colors_, float radius_, float length_, float lineWidth_) {
    
    //setup
    if (lastParticles_.size() != particles_.size()) {
        lastParticles_.clear();
        for (int i = 0; i < particles_.size(); i++) {
            lastParticles_.push_back(ofPoint());
        }
    }
    
    //draw
    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(lineWidth_);
    for (int i = 0; i < particles_.size(); i++) {
        ofSetColor(colors_[i]);
        ofDrawCircle(particles_[i], radius_);
        ofDrawLine(particles_[i], particles_[i] - (particles_[i] - lastParticles_[i]) * length_);
    }
    ofPopStyle();
    
    //update
    lastParticles_ = particles_;
}
