#include "streamFlow.h"

//--------------------------------------------------------------
void streamFlow::draw(vector<ofPoint> particles_, vector<ofColor> colors_, int length_, int fadeMode_, int skip_) {
    
    //setup
    if (pastParticles.size() != length_ || (pastParticles.size() > 0 && pastParticles[0].size() != particles_.size())) {
        pastParticles.clear();
        for (int i = 0; i < length_; i++) {
            pastParticles.push_back(particles_);
        }
    }
    
    //update
    pastParticles.push_back(particles_);
    if (pastParticles.size() > length_) pastParticles.erase(pastParticles.begin());
    
    ofVec3f vertexData[particles_.size() * length_ * 2];
    ofFloatColor colorData[particles_.size() * length_ * 2];
    for (int j = 1; j < pastParticles.size(); j++) {
        int addition = j * particles_.size() * 2;
        for (int i = 0; i < particles_.size() * 2; i += 2) {
            vertexData[addition + i] = pastParticles[j][i / 2];
            vertexData[addition + i + 1] = pastParticles[j - 1][i / 2];
            if (fadeMode_ == 0) {
                colorData[addition + i] = colors_[i / 2];
                colorData[addition + i + 1] = colors_[i / 2];
            } else if (fadeMode_ == 1) {
                colorData[addition + i] = ofColor(colors_[i / 2], ofMap(j, 1, pastParticles.size() - 1, 0, 255));
                colorData[addition + i + 1] = ofColor(colors_[i / 2], ofMap(j, 1, pastParticles.size() - 1, 0, 255));
            } else {
                colorData[addition + i] = ofColor(colors_[i / 2], ofMap(j, 1, pastParticles.size() - 1, 255, 0));
                colorData[addition + i + 1] = ofColor(colors_[i / 2], ofMap(j, 1, pastParticles.size() - 1, 255, 0));
            }
        }
    }
    vbo.setVertexData(vertexData, particles_.size() * length_ * 2, GL_DYNAMIC_DRAW);
    vbo.setColorData(colorData, particles_.size() * length_ * 2, GL_DYNAMIC_DRAW);
    
    //draw
    glLineWidth(4);
    vbo.draw(GL_LINES, 0, particles_.size() * length_ * 2);
}
