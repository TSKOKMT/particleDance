#include "energySource.h"

//--------------------------------------------------------------
vector<ofPoint> energySource::get(int num_, ofRectangle frame_, float activeRadius_) {
    
    //setup
    setup(num_, frame_);
    if (indexes.size() != num_ || (touches.size() > 0 && touches.size() != previousTouches.size())) {
        indexes.clear();
        for (int i = 0; i < num_; i++) {
            indexes.push_back(ofMap(i, 0, num_, 0, touches.size()));
        }
    }
    previousTouches = touches;
    
    //update
    if (touches.size() > 0) {
        for (int i = 0; i < particles.size(); i++) {
            if (!bActives[indexes[i]] && ofDist(particles[i], touches[indexes[i]])) bActives[indexes[i]] = true;
            
            if (bActives[indexes[i]]) centers[indexes[i]] = math.easeFilter(touches[indexes[i]], .3);
            
            if (bActives[indexes[i]]) {
                float angle = ofRandom(2 * PI);
                float length = ofRandom(100);
                particles[i] = ofPoint(cos(angle), sin(angle)) * length;
                //particles = math.easeFilter(particles, .03);
                particles[i] += centers[indexes[i]];
            } else {
                particles[i] = ofPoint(0, 0);
                //particles = math.easeFilter(particles, .5);
                particles[i] += centers[indexes[i]];
            }
        }
    }
    update();
    touches.clear();
    centers.clear();
    bActives.clear();
    
    //return
    return particles;
}

//--------------------------------------------------------------
void energySource::createTouch(ofPoint position_) {
    
    touches.push_back(position_);
    centers.push_back(ofPoint());
    bActives.push_back(false);
}
