#include "traceTrack.h"

//--------------------------------------------------------------
vector<ofPoint> traceTrack::get(int num_, ofRectangle frame_, vector<ofPolyline> polylines_, float minSpeed_, float maxSpeed_) {
    
    //setup
    setup(num_, frame_);
    num_ = ofClamp(num_, 0, INT_MAX);
    if (trackSpeeds.size() != num_) {
        int size = trackSpeeds.size();
        trackSpeeds.resize(num_);
        percents.resize(num_);
        for (int i = size; i < num_; i++) {
            trackSpeeds[i] = ofRandom(minSpeed_, maxSpeed_);
            percents[i] = ofRandom(1);
        }
    }
    
    //update
    if (polylines_.size() > 0) {
        for (int i = 0; i < particles.size(); i++) {
            int index = ofMap(i, 0, particles.size(), 0, polylines_.size());
            percents[i] += trackSpeeds[i] / 100.;
            percents[i] = ofWrap(percents[i], 0, 1);
            particles[i] = polylines_[index].getPointAtPercent(percents[i]) + frame_.getPosition();
        }
    }
    update();
    
    //return
    return particles;
}
