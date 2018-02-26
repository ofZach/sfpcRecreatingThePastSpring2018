#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    // --> ofRandom(0,100); pick a number betw 0 - 100
    // --> ofRandom(0,1); pick a number betw 0 - 1
    
    //cout << ofRandom(0,100) << endl;
    
    ofSeedRandom(0);
    
    for (int i = 0; i < 50; i++){
        cout << ofRandom(0,100) << endl;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    //ofBackground(0);
    //ofDrawCircle(ofRandom(200,400),ofRandom(200,400),50);
    
    
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
