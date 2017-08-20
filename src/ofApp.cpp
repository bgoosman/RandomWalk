#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(0);
    origin.set(windowWidth / 2, windowHeight / 2);
    position = origin;
    path.moveTo(origin);
    time = ofGetElapsedTimeMillis();
    paused = true;
    auto x = 3;
}

void ofApp::update() {
    if (timerElapsed() && !paused) {
        updateApplication();
    }
}

bool ofApp::timerElapsed() {
    uint64_t ellapsedMilliseconds = ofGetElapsedTimeMillis();
    bool readyForUpdate = ellapsedMilliseconds - time > updateInterval;
    if (readyForUpdate)
        time = ellapsedMilliseconds;
    return readyForUpdate;
}

void ofApp::updateApplication() {
    ofPoint newPosition = position + random2d(-5, 5);
    if (inWindowBounds(newPosition, padding)) {
        position = newPosition;
        path.lineTo(position);
    }

    int r = ofRandom(1, 100);
    if (r == 1) {
        ofPoint newOrigin = origin + random2d(-10, 10);
        if (inWindowBounds(newOrigin, padding)) {
            origin = newOrigin;
            path.moveTo(origin);
        }
    }
}

void ofApp::draw() {
    path.draw();
}

ofPoint ofApp::random2d(int min, int max) {
    int dx = ofRandom(min, max);
    int dy = ofRandom(min, max);
    ofPoint point;
    point.set(dx, dy);
    return point;
}

bool ofApp::inWindowBounds(ofPoint point, float padding) {
    return (point.x > padding 
        && point.x < windowWidth - padding 
        && point.y > padding 
        && point.y < windowHeight - padding);
}

void ofApp::keyPressed(int key) {
    if (key == 'f') {
        ofToggleFullscreen();
    } else if (key == ' ') {
        togglePause();
    }
}

void ofApp::togglePause() {
    paused = !paused;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
