#include "lampFly.h"

//--------------------------------------------------------------
vector<ofPoint> lampFly::get(int num_, float maxSpeed_, ofPoint center_, float maxWidth, float maxHeight_) {
    
    //setup
    if (particles.size() != num_) {
        particles.clear();
        radians.clear();
        radianSpeeds.clear();
        numOfRadians = 16;
        for (int i = 0; i < num_; i++) {
            particles.push_back(ofPoint());
            radians.push_back(vector<ofPoint>());
            radianSpeeds.push_back(vector<ofPoint>());
            for (int j = 0; j < numOfRadians; j++) {
                radians.back().push_back(ofPoint(ofRandom(2 * PI), ofRandom(2 * PI)));
                radianSpeeds.back().push_back(ofPoint(ofRandom(1), ofRandom(1)));
            }
        }
    }
    
    //update
    for (int i = 0; i < particles.size(); i++) {
        particles[i] = ofPoint(0, 0);
        for (int j = 0; j < numOfRadians; j++) {
            radians[i][j] += radianSpeeds[i][j] * maxSpeed_ / (float)numOfRadians;
            particles[i] += ofPoint(sin(radians[i][j].x), sin(radians[i][j].y));
        }
        particles[i] /= float(numOfRadians);
        particles[i] *= ofPoint(maxWidth, maxHeight_);
        particles[i] += center_;
    }
    
    //return
    return particles;
}

