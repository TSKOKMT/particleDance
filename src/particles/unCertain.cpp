#include "unCertain.h"

//--------------------------------------------------------------
vector<ofPoint> unCertain::get(int num_, ofRectangle frame_, vector<ofPolyline> masks_) {
    
    //setup
    setup(num_, frame_);
    
    //update
    for (int i = 0; i < particles.size(); i++) {
        int count = 0;
        bool bOk;
        do {
            particles[i] = math.randomPointInRectangle(frame_);
            count++;
            bOk = true;
            for (int j = 0; j < masks_.size(); j++) {
                if (masks_[j].inside(particles[i])) bOk = false;
            }
        } while (!bOk && count < 256);
    }
    update();
    
    //return
    return particles;
}
