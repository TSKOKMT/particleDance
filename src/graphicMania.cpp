#include "graphicMania.h"

//--------------------------------------------------------------
void graphicMania::draw(ofxFFApp &app) {
    
    vector<ofPoint> particles;
    vector<float> speeds;
    if (particleMode == 0) {
        for (int i = 0; i < app.people.size(); i++) {
            followYou.createPosition(ofPoint(app.getPeopleL()[i], app.frame.getCenter().y), ofClamp(ofMap(app.people[i].x, .25, .75, 1, 0), 0, 1));
        }
        for (int i = 0; i < app.people.size(); i++) {
            followYou.createPosition(ofPoint(app.getPeopleR()[i], app.frame.getCenter().y), ofClamp(ofMap(app.people[i].x, .25, .75, 0, 1), 0, 1));
        }
        particles = followYou.get(num, app.frame, ofPoint(app.frame.width / 10., app.frame.height), 2, .5);
        speeds = followYou.speeds;
    }
    else if (particleMode == 1) {
        for (int i = 0; i < app.touches.size(); i++) {
            grayHole.createForce(app.touches[i].position, pow(2, sin(app.getTimeAngle() / 60.)));
        }
        particles = grayHole.get(num, app.frame, app.getBaseSize() / 60., app.getBaseSize() / 30., app.getBaseSize() / 120.);
        speeds = grayHole.speeds;
    }
    else if (particleMode == 2) {
        particles = lampFly.get(num, parameter04, app.frame.getCenter(), app.frame.width, app.frame.height);
        speeds = lampFly.speeds;
    }
    else if (particleMode == 3) {
        for (int i = 0; i < app.touches.size(); i++) {
            leapFrog.createIsland(app.touches[i].position);
        }
        particles = leapFrog.get(num, app.frame, app.time, 2., 30.);
        speeds = leapFrog.speeds;
    }
    else if (particleMode == 4) {
        particles = onLine.get(num, app.frame, app.silhouettePolylines);
        speeds = onLine.speeds;
    }
    else if (particleMode == 5) {
        float movement = 0;
        for (int i = 0; i < app.people.size(); i++) {
            movement += app.getPeopleSpeedAbs()[i] / app.getBaseSize() * 3.;
        }
        particles = perfectBound.get(num, app.frame, 0, app.getBaseSize() / 10., movement);
        speeds = perfectBound.speeds;
    }
    else if (particleMode == 6) {
        particles = traceTrack.get(num, app.frame, app.silhouettePolylines, .1, .2);
        speeds = traceTrack.speeds;
    }
    else if (particleMode == 7) {
        particles = unCertain.get(num, app.frame, app.silhouettePolylines);
        speeds = unCertain.speeds;
    }
    else if (particleMode == 8) {
        //upsideDown.createEdges(app.silhouettePolylines);
        particles = upsideDown.get(num, app.frame, app.time, 10, ofMap(sin(app.getTimeAngle() / 60.), -1, 1, 0, 100), app.getBaseSize() / 240.);
        speeds = upsideDown.speeds;
    }
    else if (particleMode == 9) {
        for (int i = 0; i < app.touches.size(); i++) {
            waterMolecule.createTornado(app.touches[i].position, pow(1.5, sin(app.getTimeAngle())), i % 2 == 0);
            if (app.touches[i].bPressed) particleSound.play();
        }
        particles = waterMolecule.get(num, app.frame);
        speeds = waterMolecule.speeds;
    }
    else if (particleMode == 10) {
        for (int i = 0; i < app.touches.size(); i++) {
            energySource.createTouch(app.touches[i].position);
        }
        particles = energySource.get(num, app.frame, app.getBaseSize() / 10.);
        speeds = energySource.speeds;
    }
    
    
    if (filterMode == 0) {
    }
    else if (filterMode == 1) {
        particles = feebleVibe.process(particles, app.getBaseSize() / 30. * parameter01);
    }
    else if (filterMode == 2) {
        particles = slowShake.process(particles, app.getBaseSize() / 30., 1);
    }
    else if (filterMode == 3) {
        particles = superSmooth.process(particles, 24, .1);
    }
    
    vector<ofColor> colors;
    if (colorMode == 0) {
        colors = mobileYummy.get(particles.size());
    }
    else if (colorMode == 1) {
        colors = bookShelf.get(particles.size());
    }
    else if (colorMode == 2) {
        colors = dropBox.get(particles.size());
    }
    else if (colorMode == 3) {
        colors = fadeGarde.get(particles.size(), speeds, 0, 12, color01, color02);
    }
    else if (colorMode == 4) {
        colors = hueShift.get(particles.size(), parameter02 * 256, 64, bDay, toggle01);
    }
    else if (colorMode == 5) {
        colors = macBack.get(particles.size());
    }
    else if (colorMode == 6) {
        colors = monoChrome.get(particles.size(), color01);
    }
    
    
    if (bDay) ofSetColor(255);
    else ofSetColor(0);
    ofDrawRectangle(app.frame);
    
    if (bBlend) {
        if (bDay) ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
        else ofEnableBlendMode(OF_BLENDMODE_ADD);
    }
    
    if (shapeMode == 0) {
        bezierSnake.draw(particles, colors);
    }
    else if (shapeMode == 1) {
        openGo.draw(particles, colors, GL_TRIANGLES);
    }
    else if (shapeMode == 2) {
        dotSpot.draw(particles, colors);
    }
    else if (shapeMode == 3) {
        fullBloom.draw(particles, colors);
    }
    else if (shapeMode == 4) {
        halfMoon.draw(particles, colors);
    }
    else if (shapeMode == 5) {
        netWork.draw(particles, colors);
    }
    else if (shapeMode == 6) {
        paperTape.draw(particles, colors);
    }
    else if (shapeMode == 7) {
        pixieSmoke.draw(particles, colors);
    }
    else if (shapeMode == 8) {
        purePillar.draw(particles, colors, app.frame, app.getBaseSize() / 5. / sqrt(particles.size()), bDay, parameter01 * 2);
    }
    else if (shapeMode == 9) {
        quantumBone.draw(particles, colors);
    }
    else if (shapeMode == 10) {
        retinaGlass.draw(particles, colors, app.frame);
    }
    else if (shapeMode == 11) {
        separatedRoom.draw(particles, colors, app.frame);
    }
    else if (shapeMode == 12) {
        sonicWave.draw(particles, colors, ofMap(parameter01, 0, 1, .1, 1), app.getBaseSize() * parameter03, ofMap(parameter04, 0, 1, 3, 10), toggle02);
    }
    else if (shapeMode == 13) {
        streamFlow.draw(particles, colors, 16, parameter01 * 3, parameter01 * 3);
    }
    else if (shapeMode == 14) {
        swimmyFish.draw(particles, colors);
    }
    else if (shapeMode == 15) {
        tadPole.draw(particles, colors);
    }
    else if (shapeMode == 16) {
        voronoiCell.draw(particles, colors, app.frame, ofMap(parameter01, 0, 1, 0, 3));
    }
    
    ofDisableBlendMode();
    
    if (bMultiParticleSound && app.time - lastParticleSoundPlayedTime > particleSoundInterval) {
        particleSound.setMultiPlay(true);
        particleSound.setLoop(false);
        particleSound.setSpeed(pow(2, ofRandom(-1, 1)));
        particleSound.play();
        particleSoundInterval = ofRandom(minParticleSoundInterval, maxParticleSoundInterval);
        lastParticleSoundPlayedTime = app.time;
    }
    particleSound.setPan(ofRandom(sin(app.getTimeAngle() / 60. + particleMode * .7)));
    
    if (bMultiShapeSound && app.time - lastShapeSoundPlayedTime > shapeSoundInterval) {
        shapeSound.setMultiPlay(true);
        shapeSound.setLoop(false);
        shapeSound.setSpeed(pow(2, ofRandom(-1, 1)));
        shapeSound.play();
        shapeSoundInterval = ofRandom(minShapeSoundInterval, maxShapeSoundInterval);
        lastShapeSoundPlayedTime = app.time;
    }
    shapeSound.setPan(ofRandom(sin(app.getTimeAngle() / 60. + shapeMode * 1.3)));
}

//--------------------------------------------------------------
void graphicMania::shuffle() {
    
    int previousParticleMode = particleMode;
    while (particleMode == previousParticleMode) particleMode = ofRandom(10);
    if (particleMode == 0) {
        int previousNum = num;
        while (num == previousNum) num = ofRandom(64, 256);
    }
    else if (particleMode == 1) {
        int previousNum = num;
        while (num == previousNum) num = ofRandom(32, 512);
    }
    else if (particleMode == 2) {
        int previousNum = num;
        while (num == previousNum) num = ofRandom(4, 512);
    }
    else if (particleMode == 3) {
        int previousNum = num;
        while (num == previousNum) num = ofRandom(4, 512);
    }
    else if (particleMode == 4) {
        int previousNum = num;
        while (num == previousNum) num = ofRandom(32, 96);
    }
    else if (particleMode == 5) {
        int previousNum = num;
        while (num == previousNum) num = ofRandom(8, 512);
    }
    else if (particleMode == 6) {
        int previousNum = num;
        while (num == previousNum) num = ofRandom(16, 128);
    }
    else if (particleMode == 7) {
        int previousNum = num;
        while (num == previousNum) num = ofRandom(2, 128);
    }
    else if (particleMode == 8) {
        int previousNum = num;
        while (num == previousNum) num = ofRandom(16, 128);
    }
    else if (particleMode == 9) {
        int previousNum = num;
        while (num == previousNum) num = ofRandom(200, 50000 / 16);
    }
    
    int previousShapeMode = shapeMode;
    while (shapeMode == previousShapeMode || (num > 1000 && shapeMode == 8) || (num > 128 && shapeMode == 7) || (num > 300 && shapeMode == 8) || (num > 32 && shapeMode == 12) || (num < 32 && shapeMode == 13)) shapeMode = ofRandom(17);
    if (particleMode == 9 && num > 1000) shapeMode = 13;
    if (shapeMode == 11) {
        particleMode = 5;
        num = ofRandom(2, 128);
    }
    
    int previousFilterMode = filterMode;
    while (filterMode == previousFilterMode) filterMode = ofRandom(4);
    if (particleMode == 9) filterMode = 0;
    
    int previousColorMode = colorMode;
    while (colorMode == previousColorMode) colorMode = ofRandom(7);
    if (particleMode == 9) colorMode = 3;
    
    bDay = (int)ofRandom(2) == 0;
    bBlend = (int)ofRandom(2) == 0;
    
    parameter01 = ofRandom(1);
    parameter02 = ofRandom(1);
    parameter03 = ofRandom(1);
    parameter04 = ofRandom(1);
    
    toggle01 = (int)ofRandom(2) == 0;
    toggle02 = (int)ofRandom(2) == 0;
    
    if (bDay) {
        color01.setHsb(ofRandom(256), 255, ofRandom(256));
        color02.setHsb(ofRandom(256), 255, ofRandom(256));
    }
    else {
        color01.setHsb(ofRandom(256), ofRandom(256), 256);
        color02.setHsb(ofRandom(256), ofRandom(256), 256);
    }
    
    particleSound.stop();
    particleSound.unload();
    bMultiParticleSound = false;
    bTogglePlayParticleSound = false;
    if (particleMode == 0) {
        particleSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/F4.mp3");
    }
    else if (particleMode == 1) {
        particleSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/C3.mp3");
    }
    else if (particleMode == 2) {
        particleSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/E11.mp3");
        bMultiParticleSound = true;
        minParticleSoundInterval = 1;
        maxParticleSoundInterval = 15;
    }
    else if (particleMode == 3) {
        particleSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/D8.mp3");
        bMultiParticleSound = true;
        minParticleSoundInterval = .3;
        maxParticleSoundInterval = 3;
    }
    else if (particleMode == 4) {
        particleSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/B1F.mp3");
        bMultiParticleSound = true;
        minParticleSoundInterval = 30;
        maxParticleSoundInterval = 60;
    }
    else if (particleMode == 5) {
        particleSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/E1.mp3");
        bMultiParticleSound = true;
        minParticleSoundInterval = 1;
        maxParticleSoundInterval = 5;
    }
    else if (particleMode == 6) {
        particleSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/D16.mp3");
        bMultiParticleSound = true;
        minParticleSoundInterval = .1;
        maxParticleSoundInterval = 2;
    }
    else if (particleMode == 7) {
        particleSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/F8.mp3");
    }
    else if (particleMode == 8) {
        particleSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/E19.mp3");
        bMultiParticleSound = true;
        minParticleSoundInterval = 5;
        maxParticleSoundInterval = 5;
    }
    else if (particleMode == 9) {
        particleSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/A1.mp3");
    }
    if (bMultiParticleSound) {
        particleSound.setMultiPlay(true);
        particleSound.setLoop(false);
        particleSound.setSpeed(pow(2, ofRandom(-1, 1)));
        particleSoundInterval = ofRandom(1, 15);
        lastParticleSoundPlayedTime = ofGetElapsedTimef();
    }
    else if (bTogglePlayParticleSound) {
        particleSound.setMultiPlay(true);
        particleSound.setLoop(false);
    }
    else {
        particleSound.setMultiPlay(false);
        particleSound.setSpeed(pow(2, ofRandom(-1, 1)));
        particleSound.setLoop(true);
    }
    particleSound.play();
    
    shapeSound.stop();
    shapeSound.unload();
    bMultiShapeSound = false;
    bTogglePlayShapeSound = false;
    if (shapeMode == 0) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/A4.mp3");
    }
    else if (shapeMode == 1) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/A2.mp3");
        bMultiShapeSound = true;
        minShapeSoundInterval = 30;
        maxShapeSoundInterval = 60;
    }
    else if (shapeMode == 2) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/E8.mp3");
        bMultiShapeSound = true;
        minShapeSoundInterval = 2;
        maxShapeSoundInterval = 10;
    }
    else if (shapeMode == 3) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/F2.mp3");
    }
    else if (shapeMode == 4) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/A8.mp3");
        bMultiShapeSound = true;
        minShapeSoundInterval = 60;
        maxShapeSoundInterval = 90;
    }
    else if (shapeMode == 5) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/A7.mp3");
        bMultiShapeSound = true;
        minShapeSoundInterval = 120;
        maxShapeSoundInterval = 210;
    }
    else if (shapeMode == 6) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/D3.mp3");
        bMultiShapeSound = true;
        minShapeSoundInterval = .2;
        maxShapeSoundInterval = 1;
    }
    else if (shapeMode == 7) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/D15.mp3");
        bMultiShapeSound = true;
        minShapeSoundInterval = .2;
        maxShapeSoundInterval = 1;
    }
    else if (shapeMode == 8) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/A9.mp3");
        bMultiShapeSound = true;
        minShapeSoundInterval = 30;
        maxShapeSoundInterval = 60;
    }
    else if (shapeMode == 9) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/E10.mp3");
        bMultiShapeSound = true;
        minShapeSoundInterval = 1;
        maxShapeSoundInterval = 10;
    }
    else if (shapeMode == 10) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/A5.mp3");
        bMultiShapeSound = true;
        minShapeSoundInterval = 120;
        maxShapeSoundInterval = 210;
    }
    else if (shapeMode == 11) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/F6.wav");
        bMultiShapeSound = true;
        minShapeSoundInterval = 5;
        maxShapeSoundInterval = 10;
    }
    else if (shapeMode == 12) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/F7.mp3");
    }
    else if (shapeMode == 13) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/X5.mp3");
        bMultiShapeSound = true;
        minShapeSoundInterval = 10;
        maxShapeSoundInterval = 16;
    }
    else if (shapeMode == 14) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/01/3.mp3");
    }
    else if (shapeMode == 15) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/A6.mp3");
    }
    else if (shapeMode == 16) {
        shapeSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/C2.mp3");
    }
    if (bMultiShapeSound) {
        shapeSound.setMultiPlay(true);
        shapeSound.setLoop(false);
        shapeSound.setSpeed(pow(2, ofRandom(-1, 1)));
        shapeSoundInterval = ofRandom(1, 15);
        lastShapeSoundPlayedTime = ofGetElapsedTimef();
    }
    else if (bTogglePlayShapeSound) {
        shapeSound.setMultiPlay(true);
        shapeSound.setLoop(false);
    }
    else {
        shapeSound.setMultiPlay(false);
        shapeSound.setSpeed(pow(2, ofRandom(-1, 1)));
        shapeSound.setLoop(true);
    }
    shapeSound.play();
    
    natureSound.stop();
    natureSound.unload();
    natureSound.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/NATURE/" + ofToString((int)ofRandom(18)) + ".mp3");
    natureSound.setLoop(true);
    natureSound.setVolume(.4);
    natureSound.setSpeed(.4);
    natureSound.play();
    
    backSound.stop();
    backSound.unload();
    vector<string> pathes;
    pathes.push_back("/Users/tskokmt/Downloads/FRAME FREE/SOUND/F5.mp3");
    pathes.push_back("/Users/tskokmt/Downloads/FRAME FREE/SOUND/F6.mp3");
    pathes.push_back("/Users/tskokmt/Downloads/FRAME FREE/SOUND/G8.mp3");
    pathes.push_back("/Users/tskokmt/Downloads/FRAME FREE/SOUND/E11.mp3");
    pathes.push_back("/Users/tskokmt/Downloads/FRAME FREE/SOUND/E12.mp3");
    pathes.push_back("/Users/tskokmt/Downloads/FRAME FREE/SOUND/E13.mp3");
    pathes.push_back("/Users/tskokmt/Downloads/FRAME FREE/SOUND/E14.mp3");
    pathes.push_back("/Users/tskokmt/Downloads/FRAME FREE/SOUND/E15.mp3");
    pathes.push_back("/Users/tskokmt/Downloads/FRAME FREE/SOUND/E16.mp3");
    backSound.load(pathes[(int)ofRandom(pathes.size())]);
    backSound.setVolume(.4);
    backSound.setSpeed(.4);
    backSound.setLoop(true);
    backSound.play();
    
    cout << particleMode << " | ";
    cout << filterMode << " | ";
    cout << colorMode << " | ";
    cout << shapeMode << " | ";
    cout << bDay << " | ";
    cout << bBlend << " | ";
    cout << parameter01 << " | ";
    cout << parameter02 << " | ";
    cout << toggle01 << " | ";
    cout << color01 << " | ";
    cout << color02 << endl;
}
