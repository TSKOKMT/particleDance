#include "slowShake.h"

//--------------------------------------------------------------
vector<ofPoint> slowShake::process(vector<ofPoint> particles_, float amount_, float speed_) {
    
    time = ofGetElapsedTimef();
    
    particles.clear();
    for (int i = 0; i < particles_.size(); i++) {
        ofPoint addition;
        for (int j = 0; j < 4; j++) {
            float thetaX = time * (fmod(i + j, speed_ * .789) + speed_ * 1.23);
            float thetaY = time * (fmod(i + j, speed_ * .876) + speed_ * .987);
            addition += ofPoint(cos(thetaX), sin(thetaY));
        }
        addition /= 4.;
        addition *= amount_;
        particles.push_back(particles_[i] + addition);
    }
    
    return particles;
}
