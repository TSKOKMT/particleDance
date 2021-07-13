#include "hueShift.h"

//--------------------------------------------------------------
vector<ofColor> hueShift::get(int num_, int startHue_, int range_, bool bDark_, bool bBlink_) {
    
    //setup
    if (colors.size() != num_) {
        colors.clear();
        saturations.clear();
        brightnesses.clear();
        hueRationsInrange.clear();
        for (int i = 0; i < num_; i++) {
            colors.push_back(ofColor());
            if (bDark_) {
                saturations.push_back(255);
                brightnesses.push_back(ofRandom(256));
            } else {
                saturations.push_back(ofRandom(256));
                brightnesses.push_back(255);
            }
            hueRationsInrange.push_back(ofRandom(1));
        }
    }

    //update
    for (int i = 0; i < colors.size(); i++) {
        if (bBlink_) hueRationsInrange[i] = ofRandom(1);
        saturations[i] = ofRandom(256);
        colors[i].setHsb((int)ofMap(hueRationsInrange[i], 0, 1, startHue_, startHue_ + range_) % 256, saturations[i], brightnesses[i]);
    }

    //return
    return colors;
}
