#include "bezierSnake.h"

//--------------------------------------------------------------
void bezierSnake::draw(vector<ofPoint> particles_, vector<ofColor> colors_, int stepParInterval_, bool bFill_) {
    
    //setup
    int step = stepParInterval_ * (particles_.size() - 1) + 1;
    
    //draw
    //ofNoFill();
    /*ofBeginShape();
    for (int i = 0; i < step; i++) {
        float t = i / float(step);
        float nextT = (i + 1) / float(step);
        ofSetColor(tool.gradientColor(colors_[t * (colors_.size() - 1)], colors_[t * (colors_.size() - 1) + 1], math.loop(t * (particles_.size() - 1), 0, 1)));
        ofDrawLine(math.bezier(particles_, t), math.bezier(particles_, nextT));
    }
    ofEndShape();*/
    
    for (int i = 0; i < particles_.size() - 4; i += 4) {
        glLineWidth(4);
        if (bFill_) glBegin(GL_POLYGON);
        else glBegin(GL_LINE_STRIP);
        int count = 0;
        for (float j = 0; j < 1; j += 1 / 16.) {
            ofPoint vertex = ofBezierPoint(particles_[i], particles_[i + 1], particles_[i + 2], particles_[i + 3], j);
            glVertex2f(vertex.x, vertex.y);
            int addition = j * 4;
            if (count % 4 == 0) glColor3ub(colors_[i + addition].r, colors_[i + addition].g, colors_[i + addition].b);
            count++;
        }
        glEnd();
    }
}
