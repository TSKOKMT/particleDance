#include "paperTape.h"

//--------------------------------------------------------------
void paperTape::draw(vector<ofPoint> particles_, vector<ofColor> colors_, int length_) {
    
    //setup
    if (logs.size() != particles_.size()) {
        logs.clear();
        logs.resize(particles_.size());
    }
    
    //update
    for (int i = 0; i < particles_.size(); i++) {
        logs[i].push_back(particles_[i]);
        while (logs[i].size() > length_) logs[i].erase(logs[i].begin());
    }
    
    //draw
    for (int i = 0; i < particles_.size(); i++) {
        ofPoint direction;
        switch ((int)ofRandom(3)) {
            case 0:
                direction = ofPoint(5, 0, 0);
                break;
            case 1:
                direction = ofPoint(0, 5, 0);
                break;
            case 2:
                direction = ofPoint(0, 0, 5);
                break;
        }
        
        ofMesh face, frame;
        frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);

        for (int k = 0; k < logs[i].size(); k++) {
            ofPoint log = logs[i][k];

            face.addVertex(log + direction);
            face.addVertex(log - direction);

            frame.addVertex(log + direction);
            frame.addVertex(log - direction);

            if (k > 0) {
                face.addIndex(k * 2); face.addIndex(k * 2 - 1); face.addIndex(k * 2 - 2);
                face.addIndex(k * 2); face.addIndex(k * 2 + 1); face.addIndex(k * 2 - 1);

                frame.addIndex(k * 2); frame.addIndex(k * 2 - 2);
                frame.addIndex(k * 2 + 1); frame.addIndex(k * 2 - 1);
            }
        }

        frame.addIndex(0); frame.addIndex(1);
        frame.addIndex(frame.getNumVertices() - 1); frame.addIndex(frame.getNumVertices() - 2);

        ofSetColor(colors_[i]);
        face.drawFaces();

        ofSetColor(0);
        frame.drawWireframe();
    }
    
    previousParticles = particles_;
}
