#include "particleTemplate.h"

//--------------------------------------------------------------
void particleTemplate::setup(int &num_, ofRectangle frame_) {
    
    num_ = ofClamp(num_, 0, INT_MAX);
    if (particles.size() != num_) {
        int size = particles.size();
        particles.resize(num_);
        previousParticles.resize(num_);
        differences.resize(num_);
        directions.resize(num_);
        speeds.resize(num_);
        for (int i = size; i < num_; i++) {
            particles[i] = math.randomPointInRectangle(frame_);
            previousParticles[i] = particles[i];
        }
    }
}

//--------------------------------------------------------------
void particleTemplate::update() {
    
    for (int i = 0; i < particles.size(); i++) {
        differences[i] = particles[i] - previousParticles[i];
        directions[i] = atan2(differences[i].y, differences[i].x);
        speeds[i] = differences[i].length();
    }
    previousParticles = particles;
}
