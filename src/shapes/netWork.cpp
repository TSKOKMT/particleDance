#include "netWork.h"

//--------------------------------------------------------------
void netWork::draw(vector<ofPoint> particles_, vector<ofColor> colors_, int amount_) {
    
    //setup
    if (indexes.size() != particles_.size() * amount_) {
        indexes.clear();
        for (int i = 0; i < particles_.size(); i++) {
            for (int j = 0; j < amount_; j++) {
                indexes.push_back(vector<int>());
                indexes.back().push_back(ofRandom(particles_.size()));
                int value;
                do {
                    value = ofRandom(particles_.size());
                } while (value == indexes.back().back());
                indexes.back().push_back(value);
            }
        }
    }
    
    //draw
    ofPushStyle();
    for (int i = 0; i < indexes.size(); i++) {
        ofSetLineWidth(4);
        ofSetColor(colors_[indexes[i][0]], pow(ofClamp(ofMap(ofDist(particles_[indexes[i][0]], particles_[indexes[i][1]]), 0, 460, 1, 0), 0, 1), .5) * 256);
        ofDrawLine(particles_[indexes[i][0]], particles_[indexes[i][1]]);
    }
    ofPopStyle();
}
