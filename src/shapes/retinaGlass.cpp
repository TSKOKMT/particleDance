#include "retinaGlass.h"

//--------------------------------------------------------------
void retinaGlass::draw(vector<ofPoint> particles_, vector<ofColor> colors_, ofRectangle frame_, float minWidthSeed_, float maxWidthSeed_, bool bVertical_, bool bDay_) {
    
    //setup
    if (widthSeeds.size() != particles_.size()) {
        int size = widthSeeds.size();
        widthSeeds.resize(particles_.size());
        for (int i = size; i < widthSeeds.size(); i++) {
            widthSeeds[i] = ofRandom(minWidthSeed_, maxWidthSeed_);
        }
    }
    
    //draw
    for (int i = 0; i < particles_.size(); i++) {
        ofSetColor(colors_[i]);
        if (bVertical_) ofDrawRectangle(frame_.getLeft(), particles_[i].y - widthSeeds[i] * frame_.height / 2., frame_.width, widthSeeds[i] * frame_.height);
        else ofDrawRectangle(particles_[i].x - widthSeeds[i] * frame_.width / 2., frame_.getTop(), widthSeeds[i] * frame_.width, frame_.height);
    }
}
