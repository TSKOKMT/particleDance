#include "quantumBone.h"

//--------------------------------------------------------------
void quantumBone::draw(vector<ofPoint> particles_, vector<ofColor> colors_, int length_, int fadeMode_, int skip_) {
    
    //setup
    /*if (pastParticles.size() != length_ || (pastParticles.size() > 0 && pastParticles[0].size() != particles_.size())) {
        pastParticles.clear();
        for (int i = 0; i < length_; i++) {
            pastParticles.push_back(particles_);
        }
    }*/
    
    //update
    //if (ofGetFrameNum() % skip_ == 0) {
        pastParticles.push_back(particles_);
        while (pastParticles.size() > length_) {
            pastParticles.erase(pastParticles.begin());
        }
    //}
    
    ofVec3f vertexData[particles_.size() * length_];
    ofFloatColor colorData[particles_.size() * length_];
    int i = 0;
    for (int j = 0; j < pastParticles.size(); j++) {
        for (int k = 0; k < pastParticles[j].size(); k++) {
            vertexData[i] = pastParticles[j][k];
            if (colors_.size() <= k) colorData[i] = ofColor(127);
            if (fadeMode_ == 0) {
                colorData[i] = colors_[k];
            } else if (fadeMode_ == 1) {
                colorData[i] = ofFloatColor(colors_[k], ofNormalize(j, 0, pastParticles.size() - 1));
            } else {
                colorData[i] = ofFloatColor(colors_[k], ofNormalize(j, pastParticles.size() - 1, 0));
            }
            i++;
        }
    }
    vbo.setVertexData(vertexData, particles_.size() * length_, GL_DYNAMIC_DRAW);
    vbo.setColorData(colorData, particles_.size() * length_, GL_DYNAMIC_DRAW);
    
    //draw
    glPointSize(4);
    glLineWidth(4);
    //vbo.draw(GL_POINTS, 0, particles_.size() * length_);
    vbo.draw(GL_LINES, 0, particles_.size() * length_);
}
