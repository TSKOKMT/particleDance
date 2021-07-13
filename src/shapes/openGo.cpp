#include "openGo.h"

//--------------------------------------------------------------
void openGo::draw(vector<ofPoint> particles_, vector<ofColor> colors_, GLenum mode_, float lineWidth_, float pointSize_) {
    
    glPointSize(pointSize_);
    glLineWidth(lineWidth_);
    glBegin(mode_);
    for (int i = 0; i < particles_.size(); i++) {
        glVertex2f(particles_[i].x, particles_[i].y);
        glColor3ub(colors_[i].r, colors_[i].g, colors_[i].b);
    }
    glEnd();
}
