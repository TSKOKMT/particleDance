#include "fadeGrade.h"

//--------------------------------------------------------------
vector<ofColor> fadeGrade::get(int num_, vector<float> grades_, float inputMin_, float inputMax_, ofColor beginColor_, ofColor endColor_) {
    
    //setup
    if (colors.size() != num_) {
        colors.clear();
        colors.resize(num_);
    }
    
    //update
    if (grades_.size() != num_) {
        for (int i = 0; i < num_; i++) {
            colors[i] = tool.gradientColor(beginColor_, endColor_, ofNormalize(i, 0, num_), 1);
        }
    }
    else {
        for (int i = 0; i < num_; i++) {
            colors[i] = tool.gradientColor(beginColor_, endColor_, ofNormalize(grades_[i], inputMin_, inputMax_), 1);
        }
    }
    
    //return
    return colors;
}
