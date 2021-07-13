#include "waterMolecule.h"

//--------------------------------------------------------------
vector<ofPoint> waterMolecule::get(int num_, ofRectangle frame_) {
    
    //setup
    setup(num_, frame_);
    num_ = ofClamp(num_, 0, INT_MAX);
    if (!bSetupBox2d) {
        box2d.init();
        box2d.setFPS(24);
        box2d.setGravity(0, 0);
        box2d.createBounds(frame_);

        particleSystem.setPhysics(.5, 100, 1);
        particleSystem.setBodyType(b2_dynamicBody);
        //particleSystem.setParticleLifetime(180);
        particleSystem.setup(box2d.getWorld());
        
        bSetupBox2d = true;
    }
    if (particleSystem.getParticleCount() != num_) {
        particleSystem.setup(box2d.getWorld());
        for (int i = 0; i < num_; i++) {
            particleSystem.createParticle(math.randomPointInRectangle(frame_), ofPoint(0, 0));
        }
    }
    if (indexes.size() != num_ || (eyes.size() > 0 && eyes.size() != previousEyes.size())) {
        indexes.clear();
        for (int i = 0; i < num_; i++) {
            indexes.push_back(ofMap(i, 0, num_, 0, eyes.size()));
        }
    }
    previousEyes = eyes;
    
    //update
    /*for (int i = 0; i < particleSystem.getParticleCount(); i++) {
        ofPoint particle = ofPoint(particleSystem.particleSystem->GetPositionBuffer()[i].x, particleSystem.particleSystem->GetPositionBuffer()[i].y) * OFX_BOX2D_SCALE;
        ofPoint force = (ofPoint(i % 382, i / 382) * 10 - particle) / 64.;
        force.x = pow(force.x, 3);
        force.y = pow(force.y, 3);
        particleSystem.applyForce(i, force);
    }*/
    //tornado
    if (eyes.size() > 0) {
        for (int i = 0; i < particleSystem.getParticleCount(); i++) {
            ofPoint eye = eyes[indexes[i]];
            float amount = amounts[indexes[i]];
            bool bCrockwise = bClockwises[indexes[i]];
            
            ofPoint particle = ofPoint(particleSystem.particleSystem->GetPositionBuffer()[i].x, particleSystem.particleSystem->GetPositionBuffer()[i].y);
            float strength = pow(7 / ofDist(particle * OFX_BOX2D_SCALE, eye), 2.2);
            
            if (ofDist(particle * OFX_BOX2D_SCALE, eye) < 5) {
                /*particleSystem.applyForce(i, -(point_ / OFX_BOX2D_SCALE - particle) * strength * 10);*/
            } else {
                particleSystem.applyForce(i, (eye / OFX_BOX2D_SCALE - particle) * strength * amount * 100);
            }
            ofPoint difference = particle * OFX_BOX2D_SCALE - eye;
            float angle = atan2(difference.y, difference.x) + PI / 2.;
            particleSystem.applyForce(i, ofPoint(cos(angle), sin(angle)) * strength * amount * 100 * (bCrockwise ? -1 : 1));
        }
    }
    box2d.update();
    for (int i = 0; i < particleSystem.getParticleCount(); i++) {
        particles[i] = ofPoint(particleSystem.particleSystem->GetPositionBuffer()[i].x, particleSystem.particleSystem->GetPositionBuffer()[i].y) * OFX_BOX2D_SCALE;
    }
    update();
    eyes.clear();
    amounts.clear();
    bClockwises.clear();
    
    //return
    return particles;
}

//--------------------------------------------------------------
void waterMolecule::createTornado(ofPoint eye_, float amount_, bool bClockwise_) {
    
    eyes.push_back(eye_);
    amounts.push_back(amount_);
    bClockwises.push_back(bClockwise_);
}
