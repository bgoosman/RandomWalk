#pragma once

#include "ofMain.h"

static int windowWidth = 500;
static int windowHeight = 500;

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    bool timerElapsed();
    void updateApplication();
    void draw();
    void togglePause();
    ofPoint random2d(int min, int max);
    bool inWindowBounds(ofPoint point, float padding);

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    bool paused;
    float time;
    uint64_t updateInterval = 100;
    float padding = 100;
    ofPath path;
    ofPoint position;
    ofPoint origin;
};
