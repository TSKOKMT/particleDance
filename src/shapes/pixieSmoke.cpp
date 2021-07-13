#include "pixieSmoke.h"

//--------------------------------------------------------------
void pixieSmoke::draw(vector<ofPoint> particles_, vector<ofColor> colors_, float spreadSpeed_) {
    
    //setup
    if (!bNew) {
        vboPartciles = new ofxVboParticles(20000, 1000);
        vboPartciles->friction = 0.001;
        bNew = true;
    }
    
    //update
    for (int i = 0; i < particles_.size(); i++) {
        for (int j = 0; j < 32; j++) {
            vboPartciles->addParticle(particles_[i], ofPoint(ofRandom(-spreadSpeed_, spreadSpeed_), ofRandom(-spreadSpeed_, spreadSpeed_), ofRandom(-spreadSpeed_, spreadSpeed_)), colors_[i]);
        }
    }
    vboPartciles->update();
    
    //draw
    glBegin(GL_POINTS);
    for (int i = 0; i < vboPartciles->positions.size(); i++) {
        ofPoint p = vboPartciles->positions[i];
        glVertex3f(p.x, p.y, p.z);
        ofColor color = vboPartciles->colors[i];
        glColor3ub(color.r, color.g, color.b);
    }
    glEnd();
}
