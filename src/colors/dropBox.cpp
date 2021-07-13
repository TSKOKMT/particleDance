#include "dropBox.h"

//--------------------------------------------------------------
vector<ofColor> dropBox::get(int num_) {
    
    //setup
    if (colors.size() != num_) {
        palette.push_back(ofColor(168, 123, 43));
        palette.push_back(ofColor(44, 36, 127));
        palette.push_back(ofColor(23, 61, 50));
        palette.push_back(ofColor(90, 19, 44));
        palette.push_back(ofColor(247, 206, 158));
        palette.push_back(ofColor(187, 209, 232));
        palette.push_back(ofColor(120, 62, 239));
        palette.push_back(ofColor(249, 217, 87));
        palette.push_back(ofColor(205, 184, 250));
        palette.push_back(ofColor(194, 41, 43));
        palette.push_back(ofColor(172, 209, 160));
        palette.push_back(ofColor(234, 97, 45));
        palette.push_back(ofColor(219, 206, 189));
        palette.push_back(ofColor(243, 179, 166));
        palette.push_back(ofColor(40, 96, 245));
        palette.push_back(ofColor(0));
        palette.push_back(ofColor(255));
        colors.clear();
        for (int i = 0; i < num_; i++) {
            colors.push_back(palette[(int)ofRandom(palette.size())]);
        }
    }
    
    //return
    return colors;
}
