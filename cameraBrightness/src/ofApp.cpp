#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    grabber.draw(0,0);
    ofTranslate(640,0); 
    
    for (int i = 0; i < grabber.getWidth(); i+=10){
        for (int j = 0; j < grabber.getHeight(); j+=10){
            ofColor pixel = grabber.getPixels().getColor(i,j);
            float brightness = pixel.getBrightness();
            
            ofPushMatrix();
            ofTranslate(i,j);
            ofRotateZ(  ofMap(brightness, 0, 255, 0, mouseX)  );
            ofLine(-5,0,5,0);
            ofPopMatrix();
        }
    }
    
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
