#include "grayHole.h"

//--------------------------------------------------------------
vector<ofPoint> grayHole::get(int num_, ofRectangle frame_, float minRadius_, float maxRadius_, float targetObjectSize_) {
    
    //setup
    setup(num_, frame_);
    num_ = ofClamp(num_, 0, INT_MAX);
    if (!bSetupBox2d) {
        box2d.init();
        box2d.setGravity(0, 0);
        box2d.setFPS(24);
        box2d.createBounds(tool.offsetRectangle(frame_, sqrt(frame_.getArea()) / 2.));
        bSetupBox2d = true;
    }
    if (box2dRects.size() != num_) {
        while (box2dRects.size() > num_) {
            box2dRects.pop_back();
        }
        while (box2dRects.size() < num_) {
            box2dRects.push_back(ofPtr<ofxBox2dRect>(new ofxBox2dRect));
            box2dRects.back()->setPhysics(ofRandom(1, 100), ofRandom(.25, .75), ofRandom(1, 100));
            box2dRects.back()->setup(box2d.getWorld(), ofRandom(frame_.getLeft(), frame_.getRight()), ofRandom(frame_.getTop(), frame_.getBottom()), targetObjectSize_ * pow(2, ofRandom(-1, 1)), targetObjectSize_ * pow(2, ofRandom(-1, 1)));
        }
        int size = radiuses.size();
        radiuses.resize(num_);
        for (int i = size; i < num_; i++) {
            radiuses[i] = ofRandom(minRadius_, maxRadius_);
        }
    }
    if (indexes.size() != num_ || (forcePositions.size() > 0 && forcePositions.size() != previousForcePositions.size())) {
        indexes.clear();
        for (int i = 0; i < num_; i++) {
            indexes.push_back(ofMap(i, 0, num_, 0, forcePositions.size()));
        }
    }
    previousForcePositions = forcePositions;
    
    //update
    if (forcePositions.size() > 0) {
        for (int i = 0; i < particles.size(); i++) {
            float dist = forcePositions[indexes[i]].distance(box2dRects[i]->getPosition());
            box2dRects[i]->addRepulsionForce(forcePositions[indexes[i]], pow(ofMap(dist, 0, radiuses[i], 1, 0), 2) * forceAmounts[indexes[i]]);
            box2dRects[i]->addAttractionPoint(forcePositions[indexes[i]], pow(ofMap(dist, 0, radiuses[i], 0, 1), 2) * forceAmounts[indexes[i]]);
        }
    }
    box2d.update();
    for (int i = 0; i < particles.size(); i++) {
        particles[i] = box2dRects[i]->getPosition();
    }
    update();
    
    forcePositions.clear();
    forceAmounts.clear();
    
    //return
    return particles;
}

//--------------------------------------------------------------
void grayHole::createForce(ofPoint position_, float amount_) {
    
    forcePositions.push_back(position_);
    forceAmounts.push_back(amount_);
}

//--------------------------------------------------------------
void grayHole::createForces(vector<ofPoint> positions_, vector<float> amounts_) {
    
    for (int i = 0; i < min(positions_.size(), amounts_.size()); i++) {
        createForce(positions_[i], amounts_[i]);
    }
}
