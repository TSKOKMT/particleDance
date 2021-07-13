#include "onLine.h"

//--------------------------------------------------------------
vector<ofPoint> onLine::get(int num_, ofRectangle frame_, vector<ofPolyline> polylines_) {
    
    //setup
    setup(num_, frame_);
    
    //update
    if (polylines_.size() > 0) {
        for (int i = 0; i < particles.size(); i++) {
            int index = ofRandom(polylines_.size());
            float percent = ofRandom(1);
            particles[i] = polylines_[index].getPointAtPercent(percent) + frame_.getPosition();
        }
    }
    update();
    
    //return
    return particles;
}
