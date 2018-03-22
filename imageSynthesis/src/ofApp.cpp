#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    myImage.allocate(500, 500, OF_IMAGE_GRAYSCALE);
    
    // disney!
    for (int i = 0; i < 500; i++){
        for (int j = 0; j < 500; j++){
            myImage.setColor(i,j, ofColor(ofRandom(0,255)));
        }
    }
    myImage.update();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // this make a pointer (address in memory)
    // to unsigned char data
    unsigned char * data = myImage.getPixels().getData();
    
    // ? not sure about this :) (see hans)
    //cout << &data << endl;
    
//    *(data) = 100;
//    *(data+1) = 200;
//    data[0] = 100;
//    data[1] = 200;
    
    float time = ofGetElapsedTimef();
    for (int i = 0; i < 500; i++){
        for (int j = 0; j < 500; j++){
            
            // how to access a 1d array from a 2d for loop
            // y * w + x
            //data[ j * 500 + i] = sin(i*0.01)*127 + 127;
            
            float dist = ofDist(i, j, mouseX, mouseY);
            float pct = dist / 100.0;
            
            myImage.setColor(i,j, ofColor(sin(dist*0.1 + time) * 127 + 127));
//            if (dist < 100){
//                 myImage.setColor(i,j, ofColor( 255 * (1-pct)));
//            } else {
//                 myImage.setColor(i,j, ofColor(  0));
//            }
           
        }
    }
    myImage.update();
    
    //myImage.update();
    

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    myImage.draw(0,0);
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
