#include "feebleVibe.h"

//--------------------------------------------------------------
vector<ofPoint> feebleVibe::process(vector<ofPoint> particles_, float amount_) {
    
    time = ofGetElapsedTimef();
    
    particles.clear();
    for (int i = 0; i < particles_.size(); i++) {
        float length = ofRandom(amount_);
        float angle = ofRandom(2 * PI);
        particles.push_back(particles_[i] + ofPoint(cos(angle), sin(angle)) * length);
    }
    
    return particles;
}
