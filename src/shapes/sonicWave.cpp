#include "sonicWave.h"

//--------------------------------------------------------------
void sonicWave::draw(vector<ofPoint> particles_, vector<ofColor> colors_, float interval_, float endRadius_, int spendTerm_, int mode_) {
    
    //setup
    if (rippleParticles.size() != particles_.size()) {
        rippleParticles.clear();
        previousParticles.clear();
        speeds.clear();
        for (int i = 0; i < particles_.size(); i++) {
            rippleParticles.push_back(rippleParticle());
            previousParticles.push_back(ofPoint());
            speeds.push_back(0);
        }
    }
    
    //update
    for (int i = 0; i < speeds.size(); i++) {
        speeds[i] = ofDist(particles_[i], previousParticles[i]);
    }
    previousParticles = particles_;
    
    //draw
    for (int i = 0; i < rippleParticles.size(); i++) {
        rippleParticles[i].draw(particles_[i], colors_[i], interval_, endRadius_ * speeds[i], spendTerm_, mode_);
    }
}

//--------------------------------------------------------------
void sonicWave::draw(vector<ofPoint> particles_, vector<ofColor> colors_, float interval_, vector<float> endRadiuses_, int spendTerm_, int mode_) {
    
    //setup
    if (rippleParticles.size() != particles_.size()) {
        rippleParticles.clear();
        previousParticles.clear();
        for (int i = 0; i < particles_.size(); i++) {
            rippleParticles.push_back(rippleParticle());
            previousParticles.push_back(ofPoint());
        }
    }
    
    //draw
    for (int i = 0; i < rippleParticles.size(); i++) {
        float speed = ofDist(particles_[i], previousParticles[i]);
        rippleParticles[i].draw(particles_[i], colors_[i], interval_, endRadiuses_[i] * ofMap(speed, 0, 100, 0, 1), spendTerm_, mode_);
    }
    
    previousParticles = particles_;
}

//--------------------------------------------------------------
void sonicWave::rippleParticle::draw(ofPoint position_, ofColor color_, float interval_, float endRadius_, int spendTerm_, int mode_) {
    
    //update time
    time = ofGetElapsedTimef();

    //create
    if (fmod(time, interval_) < fmod(previousTime, interval_)) {
        positions.push_back(position_);
        radiuses.push_back(0);
        endRadiuses.push_back(endRadius_);
        motions.push_back(ofxTskokmtMotion());
        motions.back().begin(spendTerm_);
    }
    //update
    for (int i = 0; i < positions.size(); i++) {
        radiuses[i] = motions[i].plain() * endRadiuses[i];
    }
    //destroy
    for (int i = 0; i < positions.size(); i++) {
        if (motions[i].isFinished()) {
            positions.erase(positions.begin() + i);
            radiuses.erase(radiuses.begin() + i);
            endRadiuses.erase(endRadiuses.begin() + i);
            motions.erase(motions.begin() + i);
        }
    }
    previousTime = time;
    
    //draw
    if (mode_ == 0) {
        ofPushStyle();
        ofNoFill();
        for (int i = 0; i < positions.size(); i++) {
            ofSetLineWidth(ofMap(motions[i].power(.5), 0, 1, 5, 0));
            ofColor color = color_;
            color.setHue(color.getHue() * ofMap(i, positions.size(), 0, 1, .5));
            ofSetColor(color, ofMap(motions[i].power(.5), 0, 1, 255, 0));
            ofDrawCircle(positions[i], radiuses[i]);
        }
        ofPopStyle();
    } else {
        ofPushStyle();
        ofNoFill();
        for (int i = 0; i < positions.size(); i++) {
            ofSetLineWidth(ofMap(motions[i].power(.5), 0, 1, 5, 0));
            ofColor color = color_;
            color.setHue(color.getHue() * ofMap(i, positions.size(), 0, 1, .5));
            ofSetColor(color, ofMap(motions[i].power(.5), 0, 1, 255, 0));
            float motion = motions[i].plain();
            float step = ofMap(motion, 0, 1, endRadiuses[i] / 60., 0);
            float radius = step > 0 ? (int)(radiuses[i] / step) * step : radiuses[i];
            ofPushMatrix();
            ofTranslate(positions[i]);
            ofRotateRad(pow(ofMap(i, positions.size(), 0, 0, 1), 2) * PI);
            ofBeginShape();
            int numOfPolygon = ofMap(i, positions.size(), 0, 7, 64);
            for (int j = 0; j <= numOfPolygon; j++) {
                float theta = ofMap(j, 0, numOfPolygon, 0, 2 * PI);
                radius += sin(motion * 8 * PI + theta * 4) * radiuses[i] / 30. * motion;
                radius += sin(motion * 16 * PI + theta * 7) * radiuses[i] / 30. * motion;
                radius += sin(motion * -4 * PI + theta * -8) * radiuses[i] / 30. * motion;
                radius += sin(motion * -12 * PI + theta * -3) * radiuses[i] / 30. * motion;
                ofPoint vertex = ofPoint(cos(theta), sin(theta)) * radius;
                ofVertex(vertex);
            }
            ofEndShape();
            ofPopMatrix();
        }
        ofPopStyle();
    }
}
