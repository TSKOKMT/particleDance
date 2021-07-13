#include "voronoiCell.h"

//--------------------------------------------------------------
void voronoiCell::draw(vector<ofPoint> particles_, vector<ofColor> colors_, ofRectangle drawRect_, int mode_) {
    
    //update
    voronoi.setBounds(drawRect_);
    voronoi.setPoints(particles_);
    voronoi.generate();
    
    float position = ofMap(sin(ofGetElapsedTimef() * 2 * PI / 60.), -1, 1, .1, 1);
    int howManyTimes = position < .5 ? 4 : 1;
    cells = voronoi.getCells();
    if (mode_ == 1) {
        for (int i = 0; i < cells.size(); i++) {
            for (int j = 0; j < howManyTimes; j++) {
                vector<ofPoint> newPoints;
                cells[i].pts.push_back(cells[i].pts.front());
                for (int k = 0; k < cells[i].pts.size() - 1; k++) {
                    newPoints.push_back(cells[i].pts[k] * (1 - position) + cells[i].pts[k + 1] * position);
                    newPoints.push_back(cells[i].pts[k] * position + cells[i].pts[k + 1] * (1 - position));
                }
                cells[i].pts = newPoints;
            }
        }
    } else if (mode_ == 2) {
        for (int i = 0; i < cells.size(); i++) {
            vector<ofPoint> newPoints;
            for (int j = 0; j < howManyTimes * 10; j++) {
                float position = ofMap(j, 0, howManyTimes * 10, 0, 1);
                newPoints.push_back(ofPoint(0, 0));
                float devide = 0;
                for (int k = 0; k < cells[i].pts.size(); k++) {
                    float position2 = ofMap(k, 0, cells[i].pts.size(), 0, 1);
                    float ratio = 1 - pow(abs(math.loop((position - position2) * 2, -1, 1)), 2);
                    newPoints.back() += cells[i].pts[k] * ratio;
                    devide += ratio;
                }
                newPoints.back() /= devide;
            }
            cells[i].pts = newPoints;
        }
    }
    
    //draw
    if (mode_ == 0) {
        for (int i = 0; i < voronoi.getCells().size(); i++) {
            vector<ofPoint> vertexes = voronoi.getCells()[i].pts;
            vertexes.push_back(voronoi.getCells()[i].pts[0]);
            ofSetColor(colors_[i]);
            ofBeginShape();
            for (int j = 0; j < vertexes.size(); j++) {
                ofVertex(vertexes[j]);
            }
            ofEndShape();
        }
    } else {
        ofPushStyle();
        //ofNoFill();
        ofSetLineWidth(2);
        for (int i = 0; i < cells.size(); i++) {
            /*ofSetColor(colors_[i]);
            ofBeginShape();
            for (int j = 0; j < cells[i].pts.size(); j++) {
                ofVertex(cells[i].pts[j]);
            }
            ofEndShape(true);*/
            glBegin(GL_POLYGON);
            for (int j = 0; j < cells[i].pts.size(); j++) {
                glVertex2f(cells[i].pts[j].x, cells[i].pts[j].y);
                glColor3ub(colors_[i].r, colors_[i].g, colors_[i].b);
            }
            glEnd();
        }
        ofPopStyle();
    }
}
