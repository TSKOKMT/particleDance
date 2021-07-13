#include "purePillar.h"

//--------------------------------------------------------------
void purePillar::draw(vector<ofPoint> particles_, vector<ofColor> colors_, ofRectangle frame_, float size_, bool bDay_, int colorMode_) {
    
    //setup
    camera.enableOrtho();
    camera.setPosition(frame_.width / 2., frame_.height / 2., 2000);
    
    rotations.clear();
    sizes.clear();
    for (int y = 0; y < frame_.height; y += size_) {
        for (int x = 0; x < frame_.width; x += size_) {
            rotations.push_back(ofPoint(0, 0, 0));
            sizes.push_back(ofPoint(size_, size_, size_));
        }
    }
    
    //update
    int i = 0;
    for (int y = 0; y < frame_.height; y += size_) {
        for (int x = 0; x < frame_.width; x += size_) {
            float distance = 0;
            float angle = 0;
            for (int k = 0; k < particles_.size(); k++) {
                distance += ofClamp(pow(20 / ofDist(ofPoint(x, y), particles_[k]), .5), 0, 1) / 2.;
                ofPoint difference = particles_[k] - ofPoint(x, y);
                /*float loopSeed = ofRandom(-PI, 2 * PI);
                angle += math.loop(atan2(difference.y, difference.x), loopSeed, loopSeed + 2 * PI);*/
                angle += atan2(difference.y, difference.x);
            }
            distance /= particles_.size() / 8.;
            rotations[i] = ofPoint(0, distance * 2 * PI, angle);
            sizes[i] = ofPoint(distance * 10 * size_, size_ - size_ * distance * .75, size_ - size_ * distance * .75);
            sizes[i].x = ofClamp(sizes[i].x, 0, FLT_MAX);
            sizes[i].y = ofClamp(sizes[i].y, 0, FLT_MAX);
            sizes[i].z = ofClamp(sizes[i].z, 0, FLT_MAX);
            
            i++;
        }
    }
    //rotations = math.easeFilter(rotations, .1);
    
    //draw
    
    camera.begin();
    ofEnableDepthTest();
    
    i = 0;
    for (int y = 0; y < frame_.height; y += size_) {
        for (int x = 0; x < frame_.width; x += size_) {
            ofPoint position = ofPoint(x + size_ / 2., y + size_ / 2.);
            
            ofPushMatrix();
            ofTranslate(position);
            ofRotateZRad(rotations[i].z);
            ofRotateYRad(rotations[i].y);
            ofRotateXRad(rotations[i].x);
            
            ofFill();
            ofColor color;
            if (bDay_) color = ofColor(255);
            else color = ofColor(0);
            for (int i = 0; i < particles_.size(); i++) {
                float ratio;
                if (colorMode_ == 0) ratio = pow(ofClamp(ofMap(ofDist(particles_[i], position), 0, sqrt(frame_.getArea()) / sqrt(particles_.size()), 1, 0), 0, 1), 2);
                else ratio = size_ * 4. / sqrt(particles_.size()) / ofDist(particles_[i], position);
                if (bDay_) {
                    color.r *= ofClamp(ofMap(ratio, 1, 0, colors_[i].r / 255., 1), 0, 1);
                    color.g *= ofClamp(ofMap(ratio, 1, 0, colors_[i].g / 255., 1), 0, 1);
                    color.b *= ofClamp(ofMap(ratio, 1, 0, colors_[i].b / 255., 1), 0, 1);
                }
                else color += colors_[i] * ratio;
            }
            ofSetColor(color);
            ofDrawBox(0, 0, 0, sizes[i].x, sizes[i].y, sizes[i].z);
            
            ofPushStyle();
            
            ofNoFill();
            if (bDay_) ofSetColor(255);
            else ofSetColor(0);
            ofDrawBox(0, 0, 0, sizes[i].x, sizes[i].y, sizes[i].z);
            
            ofPopStyle();
            
            ofPopMatrix();
            
            i++;
        }
    }
    
    ofDisableDepthTest();
    camera.end();
}
