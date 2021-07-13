#include "macBack.h"

//--------------------------------------------------------------
vector<ofColor> macBack::get(int num_) {
    
    //setup
    num_ = ofClamp(num_, 0, INT_MAX);
    if (colors.size() != num_) {
        palette.push_back(ofColor(0, 0, 0));
        palette.push_back(ofColor(106, 192, 162));
        palette.push_back(ofColor(20, 175, 208));
        palette.push_back(ofColor(104, 103, 175));
        palette.push_back(ofColor(253, 184, 19));
        palette.push_back(ofColor(205, 75, 147));
        palette.push_back(ofColor(252, 221, 229));
        palette.push_back(ofColor(234, 62, 36));
        palette.push_back(ofColor(212, 166, 86));
        palette.push_back(ofColor(225, 110, 121));
        palette.push_back(ofColor(65, 83, 214));
        palette.push_back(ofColor(0, 121, 115));
        palette.push_back(ofColor(84, 85, 84));
        palette.push_back(ofColor(227, 228, 229));
        palette.push_back(ofColor(190, 191, 196));
        palette.push_back(ofColor(122, 123, 128));
        palette.push_back(ofColor(242, 222, 201));
        palette.push_back(ofColor(252, 219, 202));
        palette.push_back(ofColor(246, 211, 206));
        
        int size = colors.size();
        colors.resize(num_);
        for (int i = size; i < num_; i++) {
            colors[i] = palette[(int)ofRandom(palette.size())];
        }
        //colors = tool.shiftColors(colors);
    }
    
    //return
    return colors;
}
