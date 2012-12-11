#pragma once

#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxCvHaarFinder.h"

struct Ball {
    int x;
    int y;
    int vx;
    int vy;
    int radius;
};


class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //video
    ofVideoGrabber 		vidGrabber;
    int 				camWidth;
    int 				camHeight;
    
    string asciiCharacters;
    ofTrueTypeFont  font;
    
    
    //haar finder
    ofImage img;
    ofxCvHaarFinder finder;
    
    //balls
    Ball balls[50];

    //click to save
    int 				snapCounter;
    char 				snapString[255];
    ofTrueTypeFont		cooper;
    bool 				bSnapshot;
    float 				phase;
    
};

#endif
