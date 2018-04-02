#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    ofEnableDepthTest();
    
    cam.enableOrtho();
    
    cam.begin();
    
    float ff = ofGetElapsedTimef();
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for (int i = 0; i < 100; i++){
        
        ofPushMatrix();
        
        ofRotateX(i*sin(ff)*10.8);
        ofRotateY(i * sin(ff) * 1);
        ofTranslate(200*sin(i*0.01+ff)*sin(ff),0,0);
        ofRotateZ(-i * sin(ff)*3.2);
        ofTranslate(0,200*sin(i*0.1-ff)*sin(ff),0);
        
        
        
        ofFill();
        ofSetColor(0);
        ofDrawRectangle(mouseX,0,200, 30);
        ofNoFill();
        ofSetColor(255);
        ofDrawRectangle(mouseX,0,200, 30);
        
        ofPopMatrix();
        
    }
    
    
    
    cam.end();
    
    

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
