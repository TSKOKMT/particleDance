#include "separatedRoom.h"

//--------------------------------------------------------------
void separatedRoom::draw(vector<ofPoint> particles_, vector<ofColor> colors_, ofRectangle frame_, float lineWidth_, int mode_) {
    
    //setup
    int i = 0;
    while (i < particles_.size()) {
        if (!math.isInRectangle(particles_[i], frame_)) particles_.erase(particles_.begin() + i);
        else i++;
    }
    frame_ = tool.offsetRectangle(frame_, 10);
    rects.clear();
    rects.push_back(frame_);
    if (bVerticals.size() != particles_.size() - 1) {
        bVerticals.clear();
        for (int i = 0; i < particles_.size() - 1; i++) bVerticals.push_back((int)ofRandom(2));
    }
    
    //update
    int count = 0;
    int timeOfSpalated = 0;
    do {
        int sizeOfRects = rects.size();
        cout << "A" << endl;
        for (int i = 0; i < sizeOfRects; i++) {
            cout << "B" << endl;
            vector<ofPoint> avalableParticles;
            for (int j = 0; j < particles_.size(); j++) {
                if (math.isInRectangle(particles_[j], rects[i])) avalableParticles.push_back(particles_[j]);
                if (avalableParticles.size() == 2) break;
            }
            cout << "C" << endl;
            if (avalableParticles.size() < 2) continue;
            cout << "D" << endl;
            if (bVerticals[timeOfSpalated]) {
                float sepalatePosition = (avalableParticles[0].x + avalableParticles[1].x) / 2.;
                rects.push_back(ofRectangle(sepalatePosition, rects[i].y, rects[i].getRight() - sepalatePosition, rects[i].height));
                rects[i].width = sepalatePosition - rects[i].x;
            } else {
                float sepalatePosition = (avalableParticles[0].y + avalableParticles[1].y) / 2.;
                rects.push_back(ofRectangle(rects[i].x, sepalatePosition, rects[i].width, rects[i].getBottom() - sepalatePosition));
                rects[i].height = sepalatePosition - rects[i].y;
            }
            timeOfSpalated++;
            cout << "E" << endl;
        }
        count++;
    } while (rects.size() < particles_.size() || count < 10000);
    
    //draw
    ofSetLineWidth(lineWidth_);
    for (int i = 0; i < rects.size(); i++) {
        ofSetColor(colors_[i]);
        ofSetLineWidth(3);
        if (mode_ == 0) {
            ofDrawRectangle(rects[i]);
            ofPushStyle();
            ofNoFill();
            ofSetColor(0);
            ofDrawRectangle(rects[i]);
            ofPopStyle();
        }
        else if (mode_ == 1) {
            ofDrawEllipse(rects[i].getCenter(), rects[i].width, rects[i].height);
            ofSetColor(0);
            ofDrawEllipse(rects[i].getCenter(), rects[i].width / 2., rects[i].height / 2.);
        }
        else if (mode_ == 2) {
            ofDrawLine(rects[i].getTopLeft(), rects[i].getBottomRight());
            ofDrawLine(rects[i].getTopRight(), rects[i].getBottomLeft());
        }
        else if (mode_ == 3) {
            ofDrawLine(rects[i].getTopLeft() + ofPoint(rects[i].width * .1, 0), rects[i].getTopRight() - ofPoint(rects[i].width * .1, 0));
            ofDrawLine(rects[i].getTopLeft() + ofPoint(0, rects[i].height * .1), rects[i].getBottomLeft() - ofPoint(0, rects[i].height * .1));
            ofDrawLine(rects[i].getBottomLeft() + ofPoint(rects[i].width * .1, 0), rects[i].getBottomRight() - ofPoint(rects[i].width * .1, 0));
            ofDrawLine(rects[i].getTopRight() + ofPoint(0, rects[i].height * .1), rects[i].getBottomRight() - ofPoint(0, rects[i].height * .1));
        }
        else if (mode_ == 4) {
            ofDrawTriangle(rects[i].getTopLeft(), rects[i].getBottomLeft(), ofPoint(rects[i].getCenter().x, rects[i].getBottom()));
            ofDrawTriangle(rects[i].getTopRight(), rects[i].getBottomRight(), ofPoint(rects[i].getCenter().x, rects[i].getTop()));
        }
    }
}
