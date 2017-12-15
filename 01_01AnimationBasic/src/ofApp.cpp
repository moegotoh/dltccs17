#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofBackground(0, 0, 0); //背景色を黒に
    ofEnableBlendMode(OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update(){
    //位置を更新
    for(int i = 0 ; i < location.size() ; i++){
        location[i] += velocity[i];
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //計算した位置に円を描画
    int r = 10;
    
    //ofSetColor(255);
    ofBeginShape();
    ofNoFill();
    
    
     for(int i = 0 ; i < location.size() ; i++){
         
//         ofSetColor(color[i]);
         ofSetColor(color[i]);
         ofDrawCircle(location[i], r); //半径20の円を描画
         //ofCurveVertex(location[i]);
         
         if(location[i].x > ofGetWidth() || (location[i].x < 0)){
             velocity[i].x *= -1;
         }
         
         if(location[i].y > ofGetHeight() || (location[i].y < 0)){
             velocity[i].y *= -1;
         }
         if(location[i].z > ofGetHeight() || (location[i].z < 0)){
             velocity[i].z *= -1;
         }
     }
    
    ofEndShape();
    ofSetColor(100, 100, 100);
    ofDrawBitmapString(location.size(),20,20);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 'k'){
        location.clear();
        velocity.clear();
        color.clear();
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
    
    ofVec3f loc = ofVec3f(x, y, 0);
    location.push_back(loc);
    
    ofVec3f vel = ofVec3f(ofRandom(-2.2), ofRandom(-2, 2), ofRandom(-2, 2));
    velocity.push_back(vel);
    
    ofColor col = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    color.push_back(col);
    
    if(location.size() > MAX){
        location.erase(location.begin());
        velocity.erase(velocity.begin());
        color.erase(color.begin());
    }
    
    
    //location[count].set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
    //velocity[count].set(ofRandom(-10.10), ofRandom(-10, 10), ofRandom(-10, 10));
    //color[count].set(ofRandom(255), ofRandom(255), ofRandom(255));
    //location.x = 0;
    //location.y = 0;
    

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
