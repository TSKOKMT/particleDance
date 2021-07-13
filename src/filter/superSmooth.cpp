#include "superSmooth.h"

//--------------------------------------------------------------
vector<ofPoint> superSmooth::process(vector<ofPoint> particles_, int mean_, float ease_) {
    
    particles_ = math.meanFilter(particles_, mean_);
    particles_ = math.easeFilter(particles_, ease_);
    return particles_;
}
