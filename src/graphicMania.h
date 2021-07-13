#pragma once

#include "ofMain.h"

#include "ofxFFApp.h"
#include "ofxFFSound.h"

#include "particle.h"
#include "color.h"
#include "shape.h"
#include "filter.h"

class graphicMania {

public:
    void draw(ofxFFApp &app);
    
    void shuffle();
    
    int num = 64;
    
    int recipeMode = 0;
    
    bool bDay = false;
    bool bBlend = true;
    
    float parameter01;
    float parameter02;
    float parameter03;
    float parameter04;
    bool toggle01;
    bool toggle02;
    ofColor color01;
    ofColor color02;
    
    int mode = 0;
        
    //particle
    followYou followYou;
    grayHole grayHole;
    lampFly lampFly;
    leapFrog leapFrog;
    onLine onLine;
    perfectBound perfectBound;
    traceTrack traceTrack;
    unCertain unCertain;
    upsideDown upsideDown;
    waterMolecule waterMolecule;
    energySource energySource;
    int particleMode = 1;
    
    //filter
    almostCenter almostCenter;
    feebleVibe feebleVibe;
    slowShake slowShake;
    superSmooth superSmooth;
    wrapFilm wrapFilm;
    int filterMode = -1;
    
    //color
    mobileYummy mobileYummy;
    bookShelf bookShelf;
    dropBox dropBox;
    fadeGrade fadeGarde;
    hueShift hueShift;
    macBack macBack;
    monoChrome monoChrome;
    int colorMode = 0;

    //shape
    bezierSnake bezierSnake;
    dotSpot dotSpot;
    fullBloom fullBloom;
    halfMoon halfMoon;
    netWork netWork;
    paperTape paperTape;
    pixieSmoke pixieSmoke;
    purePillar purePillar;
    quantumBone quantumBone;
    retinaGlass retinaGlass;
    separatedRoom separatedRoom;
    sonicWave sonicWave;
    streamFlow streamFlow;
    swimmyFish swimmyFish;
    tadPole tadPole;
    voronoiCell voronoiCell;
    openGo openGo;
    int shapeMode = 10;
    
    ofSoundPlayer particleSound;
    bool bMultiParticleSound;
    float particleSoundInterval;
    float minParticleSoundInterval;
    float maxParticleSoundInterval;
    float lastParticleSoundPlayedTime;
    bool bTogglePlayParticleSound;
    
    ofSoundPlayer shapeSound;
    bool bMultiShapeSound;
    float shapeSoundInterval;
    float minShapeSoundInterval;
    float maxShapeSoundInterval;
    float lastShapeSoundPlayedTime;
    bool bTogglePlayShapeSound;
    
    ofSoundPlayer colorSound;
    
    ofSoundPlayer natureSound;
    
    ofSoundPlayer backSound;
};
