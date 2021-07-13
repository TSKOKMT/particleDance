#include "halfMoon.h"

//--------------------------------------------------------------
void halfMoon::draw(vector<ofPoint> particles_, vector<ofColor> colors_, float minRadius_, float maxRadius_) {
    
    //setup
    if (lastParticles.size() != particles_.size()) {
        lastParticles.clear();
        radiuses.clear();
        for (int i = 0; i < particles_.size(); i++) {
            lastParticles.push_back(ofPoint());
            radiuses.push_back(ofRandom(minRadius_, maxRadius_));
        }
    }
    
    //draw
    for (int i = 0; i < particles_.size(); i++) {
        ofPath path;
        path.arc(0, 0, radiuses[i], radiuses[i], -90, 90);
        path.setFilled(true);
        path.setColor(colors_[i]);
        ofPushMatrix();
        ofTranslate(particles_[i]);
        ofPoint difference = particles_[i] - lastParticles[i];
        float angle = math.easeFilter(atan2(difference.y, difference.x), .9);
        ofRotateRad(angle);
        path.draw();
        ofPopMatrix();
    }
    
    //update
    lastParticles = particles_;
}
