#include "leapFrog.h"

//--------------------------------------------------------------
vector<ofPoint> leapFrog::get(int num_, ofRectangle frame_, float &time_, float minInterval_, float maxInterval_) {
    
    //setup
    setup(num_, frame_);
    num_ = ofClamp(num_, 0, INT_MAX);
    if (intervals.size() != num_) {
        int size = intervals.size();
        intervals.resize(num_);
        for (int i = size; i < num_; i++) {
            intervals[i] = ofRandom(minInterval_, maxInterval_);
        }
    }
    
    //update
    if (islands.size() > 0) {
        for (int i = 0; i < particles.size(); i++) {
            float percent = fmod(time_, intervals[i]) / intervals[i];
            ofPoint from = islands[ofWrap(floor(time_ / intervals[i]), 0, islands.size())];
            ofPoint to = islands[ofWrap(ceil(time_ / intervals[i]), 0, islands.size())];
            particles[i] = math.map(percent, 0, 1, from, to);
        }
    }
    update();
    islands.clear();
    
    return particles;
}

//--------------------------------------------------------------
void leapFrog::createIsland(ofPoint island_) {
    
    islands.push_back(island_);
}

//--------------------------------------------------------------
void leapFrog::createIslands(vector<ofPoint> islands_) {
    
    for (int i = 0; i < islands_.size(); i++) {
        createIsland(islands_[i]);
    }
}
