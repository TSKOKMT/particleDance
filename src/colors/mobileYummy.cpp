#include "mobileYummy.h"

//--------------------------------------------------------------
vector<ofColor> mobileYummy::get(int num_) {
    
    //setup
    if (colors.size() != num_) {
        colors.clear();
        for (int i = 0; i < num_; i++) {
            colors.push_back(ofColor());
            switch ((int)ofRandom(10)) {
                case 0:
                    colors.back() = ofColor(255, 59, 48);
                    break;
                case 1:
                    colors.back() = ofColor(255, 149, 0);
                    break;
                case 2:
                    colors.back() = ofColor(255, 204, 0);
                    break;
                case 3:
                    colors.back() = ofColor(52, 199, 89);
                    break;
                case 4:
                    colors.back() = ofColor(90, 200, 250);
                    break;
                case 5:
                    colors.back() = ofColor(0, 122, 255);
                    break;
                case 6:
                    colors.back() = ofColor(255, 45, 85);
                    break;
                case 7:
                    colors.back() = ofColor(175, 82, 222);
                    break;
                case 8:
                    colors.back() = ofColor(242, 242, 247);
                break;
                case 9:
                    colors.back() = ofColor(28, 28, 30);
                break;
                default:
                    break;
            }
        }
    }
    
    //return
    return colors;
}
