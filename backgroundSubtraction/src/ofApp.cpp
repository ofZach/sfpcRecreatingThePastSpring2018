#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
    background.allocate(640,480, OF_IMAGE_COLOR);
    threshold.allocate(640,480, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    
    if (bSnapshot){
        
        background.setFromPixels(grabber.getPixels());
        background.update();
        
        bSnapshot = false;
    }
    
    for (int x = 0; x < 640; x++){
        for (int y = 0; y < 480; y++){
            // let's compare
            // pixel xy in video
            // vs pixel xy in background
            // and if abs(diff) > ...
            // do something.
            int camBrightness = grabber.getPixels().getColor(x,y).getBrightness();
            int backgroundBrightness = background.getColor(x,y).getBrightness();
            
            int diff = abs(camBrightness - backgroundBrightness);
            
            //threshold.setColor(x,y,ofColor(diff));
            if (diff > mouseX){
                threshold.setColor(x,y,ofColor(255));
            } else {
                threshold.setColor(x,y,ofColor(0));
            }
        }
    }
    threshold.update();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    grabber.draw(0,0);
    background.draw(640,0);
    threshold.draw(0,480);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
        bSnapshot = true;
    }
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
