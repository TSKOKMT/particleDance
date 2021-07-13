#include "followYou.h"

//--------------------------------------------------------------
vector<ofPoint> followYou::get(int num_, ofRectangle frame_, ofPoint size_, int meanNum_, float easeAmount_) {
    
    //setup
    setup(num_, frame_);
    num_ = ofClamp(num_, 0, INT_MAX);
    if (mathes.size() != num_) {
        mathes.resize(num_);
    }
    indexes.clear();
    
    float weightSum = 0;
    for (int i = 0; i < weights.size(); i++) {
        weightSum += weights[i];
    }
    for (int i = 0; i < weights.size(); i++) {
        weights[i] /= weightSum;
    }
    
    for (int i = 0; i < num_; i++) {
        int index = 0;
        float value = 0;
        for (int j = 0; j < weights.size(); j++) {
            value += weights[j];
            if (value > i / (float)num_) {
                index = j;
                break;
            }
        }
        indexes.push_back(index);
    }
    
    //update
    if (positions.size() > 0) {
        for (int i = 0; i < particles.size(); i++) {
            ofPoint addition = ofPoint(ofRandom(-size_.x / 2., size_.x / 2.), ofRandom(-size_.y / 2., size_.y / 2.)) * (1 + meanNum_ / 100.) / pow(easeAmount_, .5);
            addition = mathes[i].meanFilter(addition, meanNum_);
            addition = mathes[i].easeFilter(addition, easeAmount_);
            particles[i] = positions[indexes[i]] + addition;
        }
    }
    update();
    positions.clear();
    weights.clear();
    
    //return
    return particles;
}

//--------------------------------------------------------------
void followYou::createPosition(ofPoint position_, float weight_) {
    
    positions.push_back(position_);
    weights.push_back(weight_);
}
