#include "dotSpot.h"

//--------------------------------------------------------------
void dotSpot::draw(vector<ofPoint> particles_, vector<ofColor> colors_, float minRadius_, float maxRadius_, bool bRandomRoate_) {
    
    //setup
    if (radiuses.size() != particles_.size()) {
        int size = radiuses.size();
        radiuses.resize(particles_.size());
        for (int i = size; i < particles_.size(); i++) {
            radiuses[i] = ofRandom(minRadius_, maxRadius_);
        }
    }
    
    //draw
    if (bRandomRoate_) ofSetCircleResolution(ofRandom(3, 7));
    for (int i = 0; i < particles_.size(); i++) {
        ofSetColor(colors_[i]);
        ofPushMatrix();
        ofTranslate(particles_[i]);
        if (bRandomRoate_) ofRotateRad(ofRandom(2 * PI));
        ofDrawCircle(0, 0, radiuses[i]);
        ofPopMatrix();
    }
    ofSetCircleResolution(128);
}
