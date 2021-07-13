#include "perfectBound.h"

//--------------------------------------------------------------
vector<ofPoint> perfectBound::get(int num_, ofRectangle frame_, float minSpeed_, float maxSpeed_, float movement_) {
    
    //setup
    setup(num_, frame_);
    num_ = ofClamp(num_, 0, INT_MAX);
    if (directions2.size() != num_) {
        int size = directions2.size();
        directions2.resize(num_);
        speeds2.resize(num_);
        for (int i = size; i < num_; i++) {
            directions2[i] = ofRandom(2 * PI);
            speeds2[i] = ofRandom(minSpeed_, maxSpeed_);
        }
    }
    
    //update
    for (int i = 0; i < particles.size(); i++) {
        particles[i] += ofPoint(cos(directions2[i]), sin(directions2[i])) * speeds2[i] * movement_;
        if (particles[i].x < frame_.getLeft()) {
            particles[i].x = frame_.getLeft() + (frame_.getLeft() - particles[i].x);
            directions2[i] = PI - directions2[i];
        } else if (particles[i].x > frame_.getRight()) {
            particles[i].x = frame_.getRight() - (particles[i].x - frame_.getRight());
            directions2[i] = PI - directions2[i];
        } else if (particles[i].y < frame_.getTop()) {
            particles[i].y = frame_.getTop() + (frame_.getTop() - particles[i].y);
            directions2[i] *= -1;
        } else if (particles[i].y > frame_.getBottom()) {
            particles[i].y = frame_.getBottom() - (particles[i].y - frame_.getBottom());
            directions2[i] *= -1;
        }
    }
    update();
    
    //return
    return particles;
}
