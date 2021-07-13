#include "monoChrome.h"

//--------------------------------------------------------------
vector<ofColor> monoChrome::get(int num_, ofColor color_) {
    
    //setup
    if (colors.size() != num_ || colors.front() != color_) {
        colors.clear();
        for (int i = 0; i < num_; i++) {
            colors.push_back(color_);
        }
    }
    
    //return
    return colors;
}
