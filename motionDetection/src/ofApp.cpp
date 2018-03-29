#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
    threshold.allocate(640,480, OF_IMAGE_COLOR);
    prevFrame.allocate(640,480, OF_IMAGE_COLOR);
    whiteCountSmooth = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    
    if (grabber.isFrameNew()){
        
        for (int x = 0; x < 640; x++){
            for (int y = 0; y < 480; y++){
                // let's compare
                // pixel xy in video
                // vs pixel xy in background
                // and if abs(diff) > ...
                // do something.
                int camBrightness = grabber.getPixels().getColor(x,y).getBrightness();
                int prevFrameBrightness = prevFrame.getColor(x,y).getBrightness();
                
                int diff = abs(camBrightness - prevFrameBrightness);
                
                //threshold.setColor(x,y,ofColor(diff));
                if (diff > mouseX){
                    threshold.setColor(x,y,ofColor(255));
                } else {
                    threshold.setColor(x,y,ofColor(0));
                }
            }
        }
        threshold.update();
        
        
        
        prevFrame.setFromPixels(grabber.getPixels());
        prevFrame.update();
        
    }
    
    
    
    //cout << whiteCount << endl;
    
    
    
//    if (bSnapshot){
//
//        background.setFromPixels(grabber.getPixels());
//        background.update();
//
//        bSnapshot = false;
//    }
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    grabber.draw(0,0);
    prevFrame.draw(640,0);
    threshold.draw(0,480);
    
    
    int whiteCount = 0;
    for (int x = 0; x < 640; x++){
        for (int y = 0; y < 480; y++){
            if (threshold.getColor(x,y).getBrightness() > 127){
                whiteCount ++;
            }
        }
    }
    
    whiteCountSmooth = 0.99 * whiteCountSmooth + 0.01 * whiteCount;
    
    
    float radius = ofMap(whiteCountSmooth, 0, 10000, 0, 200, true);
    ofDrawCircle(800,600, radius);
    
    
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
