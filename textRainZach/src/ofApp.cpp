#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    camera.setup(640,480);
    thresholdImg.allocate(640, 480, OF_IMAGE_COLOR);
    
    font.load("Helvetica.ttc", 10);
    
    for (int i = 0; i < 100; i++){
        // make a point object
        ofPoint temp;
        // give it a random position
        temp.set(ofRandom(0,640), 0);
        // add it to the growable array called pts.
        pts.push_back(temp);
    }
    
    bDebug = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){

    camera.update();
    
    for (int x = 0; x < 640; x++){
        for (int y = 0; y < 480; y++){
            ofColor pixel = camera.getPixels().getColor(x,y);
            if (pixel.getBrightness() > mouseX){
                thresholdImg.setColor(x,y, ofColor(255));
            } else {
                thresholdImg.setColor(x,y, ofColor(0));
            }
        }
    }
    thresholdImg.update();
    
    for (int i = 0; i < pts.size(); i++){
        
        // what color am I on top of ???
        ofColor pixel = thresholdImg.getColor(pts[i].x, ofClamp(pts[i].y+1, 0, 480-1));
        
        if (pixel.getBrightness() > 127){
            pts[i].y += 3;
        } else {
            // ; // ?? :( didn't work
            int yPos = pts[i].y;
            int xPos = pts[i].x;
            
            for (int y = yPos; y >= 0; y--){
                ofColor otherPixel = thresholdImg.getColor(xPos,y);
                if (otherPixel.getBrightness() > 127){
                    pts[i].y = y;
                    break;
                }
                
            }
        }
        if (pts[i].y > 480){
            pts[i].y = 0;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    camera.draw(0,0);
    if (bDebug){
        thresholdImg.draw(640,0);
    }
    
    ofSetColor(255,0,0);
    string message = "hello world ! ";
    for (int i = 0; i < pts.size(); i++){
        string temp = "";
        temp += message[i % message.size()];
        font.drawString(temp, pts[i].x, pts[i].y);
        //ofCircle(pts[i], 4);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
        bDebug = !bDebug;
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
