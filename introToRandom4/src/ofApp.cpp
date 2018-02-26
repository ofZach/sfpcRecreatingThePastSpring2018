#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    ofSeedRandom(mouseX*1000);
    
    ofPoint a(200,200);
    ofPoint b(400,200);
    ofPoint c(400,400);
    ofPoint d(200,400);
    
    a.x = a.x + ofRandom(-mouseY,mouseY);
    b.x = b.x + ofRandom(-mouseY,mouseY);
    c.x = c.x + ofRandom(-mouseY,mouseY);
    d.x = d.x + ofRandom(-mouseY,mouseY);
    
    
    ofDrawLine(a,b);
    ofDrawLine(b,c);
    ofDrawLine(c,d);
    ofDrawLine(d,a);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
