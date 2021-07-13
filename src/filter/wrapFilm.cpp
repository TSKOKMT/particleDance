#include "wrapFilm.h"

//--------------------------------------------------------------
vector<ofPoint> wrapFilm::process(vector<ofPoint> particles_, float minJoinDist_) {
    
    //nearJoin
    vector<vector<ofPoint>> groups;
    if (particles_.size() >= 4) {
        //nearJoin
        groups.push_back(vector<ofPoint>());
        groups.back().push_back(particles_.front());
        for (int i = 1; i < particles_.size(); i++) {
            bool bNear;
            for (int j = 0; j < groups.size(); j++) {
                bNear = false;
                for (int k = 0; k < groups[j].size(); k++) {
                    if (ofDist(particles_[i], groups[j][k]) <= minJoinDist_) {
                        bNear = true;
                        break;
                    }
                }
                if (bNear) {
                    groups[j].push_back(particles_[i]);
                    break;
                }
            }
            if (!bNear) {
                groups.push_back(vector<ofPoint>());
                groups.back().push_back(particles_[i]);
            }
        }
        //convexHull
        particles_.clear();
        for (int i = 0; i < groups.size(); i++) {
            vector<ofPoint> hull = convexHull.getConvexHull(groups[i]);
            particles_.insert(particles_.end(), hull.begin(), hull.end());
        }
    }
    
    //return
    return particles_;
}
