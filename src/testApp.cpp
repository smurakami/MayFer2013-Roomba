#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  roomba = new Roomba();
  roomba->setField(&field);
  ofEnableSmoothing();
  ofSetFrameRate(30);
  roomba->setSensorVal();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
  ofBackgroundGradient(ofColor::gray, ofColor(30, 10, 30), OF_GRADIENT_CIRCULAR);
  //フィールド描写
  field.draw();
  //ルンバの描写
  roomba->draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
  float theta;
  float roombaX = roomba->body.xForDraw();
  float roombaY = roomba->body.yForDraw();
  
  if(x >= roombaX){
    theta = atanf((y - roombaY)/(x - roombaX));
    if(theta < 0) theta += 2 * M_PI;
  }else{
    theta = atanf((y - roombaY)/(x - roombaX)) + M_PI;
  }
  roomba->body.theta = theta;
  roomba->setSensorVal();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------


































