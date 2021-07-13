#include "upsideDown.h"

//--------------------------------------------------------------
vector<ofPoint> upsideDown::get(int num_, ofRectangle frame_, float &time_, float interval_, float gravity_, float targetObjectRadius_) {
    
    //setup
    setup(num_, frame_);
    if (!bSetupBox2d) {
        box2d.init();
        box2d.setGravity(0, 0);
        box2d.setFPS(24);
        box2d.createBounds(frame_);
        bSetupBox2d = true;
    }
    if (box2dCircles.size() != num_) {
        while (box2dCircles.size() > num_) {
            box2dCircles.pop_back();
        }
        while (box2dCircles.size() < num_) {
            box2dCircles.push_back(ofPtr<ofxBox2dCircle>(new ofxBox2dCircle));
            box2dCircles.back()->setPhysics(ofRandom(1, 100), ofRandom(.25, .75), ofRandom(1, 100));
            box2dCircles.back()->setup(box2d.getWorld(), ofRandom(frame_.getLeft(), frame_.getRight()), ofRandom(frame_.getTop(), frame_.getBottom()), targetObjectRadius_ * pow(2, ofRandom(-1, 1)));
        }
    }
    
    //update
    box2d.setGravity(ofRandom(-gravity_ / 10., gravity_ / 10.), ofMap((int)(time_ / interval_) % 2, 0, 1, -gravity_, gravity_));
    box2d.update();
    for (int i = 0; i < particles.size(); i++) {
        particles[i] = box2dCircles[i]->getPosition();
    }
    update();
    edges.clear();
    
    //return
    return particles;
}

//--------------------------------------------------------------
void upsideDown::createEdges(vector<ofPolyline> polylines_) {
    
    for (int i = 0; i < polylines_.size(); i++) {
        edges.push_back(ofPtr<ofxBox2dEdge>(new ofxBox2dEdge));
        edges.back()->addVertexes(polylines_[i]);
        edges.back()->setPhysics(0, 1, 1);
        edges.back()->create(box2d.getWorld());
    }
}
