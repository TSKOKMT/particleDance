#include "almostCenter.h"

//--------------------------------------------------------------
vector<ofPoint> almostCenter::process(vector<ofPoint> particles_) {
    
    //process
    vector<ofPoint> points;
    points.resize(1);
    for (int i = 0; i < particles_.size(); i++) {
        points.front() += particles_[i];
    }
    points.front() /= float(particles_.size());
    
    //return
    return points;
}
