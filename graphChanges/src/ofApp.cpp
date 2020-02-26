// Refer to the README.md in the example's root folder for more information on usage

#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    std::cout << "Loaded" << std::endl;
    for(int i = 0; i < 240; i++)
    {
        planetsVector.push_back(planets());
        planetsVector[i].x = ofRandom(10, 350);
        planetsVector[i].y = ofRandom(10, 300);
        planetsVector[i].radius = ofRandom(10, 20);
        planetsVector[i].r = 30;
        planetsVector[i].g = ofRandom(i, i+6);
        planetsVector[i].b = ofRandom(i, i+10);
    }
    for(int i = 0; i < 740; i++)
    {
        starsVector.push_back(stars());
        starsVector[i].x = ofRandom(-960, ofGetWidth());
        starsVector[i].y = ofRandom(-540, ofGetHeight());
        starsVector[i].radius = ofRandom(2, 4);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    rotation++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    int randomComet = ofRandom(1, 25);
    Comet kometa;
    if(randomComet%10 == 0)
    {
        kometa.x = ofRandom(-960, 100);
        kometa.y = ofRandom(-540, 100);
        kometa.endx = ofRandom(-960, 1800);
        kometa.vx = ofRandom(1, 2);
        kometa.vy = ofRandom(-4, 4);
        while(kometa.x < kometa.endx)
        {
            ofPoint pt;
            ofSetColor(255, 255, 255);
            kometa.x += kometa.vx;
            kometa.y += kometa.vy;
            pt.set(kometa.x, kometa.y);
            cometLine.addVertex(pt);
            cometLine.draw();
        }
        cometLine.clear();
    }
    for(int i = 1; i < starsVector.size(); i++)
    {
        ofSetColor(250, 250, 250);
        ofCircle(starsVector[i].x, starsVector[i].y, starsVector[i].radius);
    }
    for(int i = 0; i < planetsVector.size(); i++)
    {
        ofSetColor(planetsVector[i].r, planetsVector[i].g, planetsVector[i].b);
        ofRotate(0.01 * rotation);
        ofCircle(planetsVector[i].x, planetsVector[i].y, planetsVector[i].radius);
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){

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
