#include "bookShelf.h"

//--------------------------------------------------------------
vector<ofColor> bookShelf::get(int num_) {
    
    //setup
    if (colors.size() != num_) {
        palette.push_back(ofColor(132, 239, 230));
        palette.push_back(ofColor(254, 79, 97));
        palette.push_back(ofColor(251, 216, 0));
        palette.push_back(ofColor(149, 0, 254));
        palette.push_back(ofColor(160, 254, 0));
        colors.clear();
        for (int i = 0; i < num_; i++) {
            colors.push_back(palette[(int)ofRandom(palette.size())]);
        }
    }
    
    //return
    return colors;
}
