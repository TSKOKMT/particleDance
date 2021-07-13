#include "swimmyFish.h"

//--------------------------------------------------------------
void swimmyFish::draw(vector<ofPoint> particles_, vector<ofColor> colors_, float minRadius_, float maxRadius_, int minLength_, int maxLength_) {
    
    //setup
    if (radiuses.size() != particles_.size()) {
        int size = radiuses.size();
        radiuses.resize(particles_.size());
        graphics.resize(particles_.size());
        lengthes.resize(particles_.size());
        for (int i = size; i < particles_.size(); i++) {
            radiuses[i] = ofRandom(minRadius_, maxRadius_);
            lengthes[i] = ofRandom(minLength_, maxLength_);
        }
    }
    
    //draw
    for (int i = 0; i < particles_.size(); i++) {
        ofSetColor(colors_[i]);
        graphics[i].drawSwimmy(particles_[i], radiuses[i], lengthes[i]);
    }
}
