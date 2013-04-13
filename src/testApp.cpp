#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofEnableSmoothing();
  ofSetFrameRate(30);
  srand(time(NULL));
  runFinished = false;
  
  for(int i = 0; i < GEN_SIZE; i++){
    currentGen[i] = new Roomba();
    currentGen[i]->setField(&field);
    currentGen[i]->setRandomDNABySize(DEFAULT_TREE_SIZE);
  }
  
  for(int i = 0; i < ELETE_SIZE; i++){
    elete[i] = NULL;
  }
  
//  roomba = new Roomba();
//  roomba->setField(&field);
//  roomba->setSensorVal();
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
  for(int i = 0; i < ELETE_SIZE; i++){
    if(elete[i]) elete[i]->draw();
  }
  
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
  if(key == 'r'){
    if(runFinished == false){
      cout << "running..." << endl;
      for(int i = 0; i < GEN_SIZE; i++){
        currentGen[i]->run();
      }
      cout << "finished!" << endl;
      runFinished = true;
    }
  }
  
  if(key == 'p'){
    for(int i = 0; i < GEN_SIZE; i++){
      currentGen[i]->getDNA()->printTree();
    }
  }
  
  if(key == 'g'){
    cout << "step gen..." << endl;
    stepGen();
    cout << "finished!" << endl;
  }
  
  if(key == 's'){
    for(int i = 0; i < ELETE_SIZE; i++){
      if(elete[i])
        cout << "eltete " << i << ": " << elete[i]->getScore() << endl;
    }
  }
//  if(key == 'd'){
//    for(int i = 0; i < GEN_SIZE; i++){
//      delete currentGen[i];
//      currentGen[i] = NULL;
//    }
//  }
  
  if(key == 't'){
    cout << "test" << endl;
    
    crossover(currentGen[0], currentGen[1]);
    
  }
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
//  float theta;
//  float roombaX = roomba->body.xForDraw();
//  float roombaY = roomba->body.yForDraw();
//  
//  if(x >= roombaX){
//    theta = atanf((y - roombaY)/(x - roombaX));
//    if(theta < 0) theta += 2 * M_PI;
//  }else{
//    theta = atanf((y - roombaY)/(x - roombaX)) + M_PI;
//  }
//  roomba->body.theta = theta;
//  roomba->setSensorVal();
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
//                         GP PROGRAM
//--------------------------------------------------------------

void testApp::stepGen(){
  if(runFinished == false){
    for(int i = 0; i < GEN_SIZE; i++){
      currentGen[i]->run();
    }
    runFinished = true;
  }

  for(int i = 0; i < GEN_SIZE; i++){
    int selecter = roulette();
    int dice = rand() % MAX_PROBABILITY;
    Roomba * next;

    //まずは交叉を実装
    int partnerIndex = roulette();
    next = crossover(currentGen[selecter], currentGen[partnerIndex]);

    
//    if(dice < CROSSOVER_PROBABILITY){
//      int partnerIndex = roulette();
//      next = crossover(currentGen[selecter], currentGen[partnerIndex]);
//    }else if(dice < CROSSOVER_PROBABILITY + INVERTION_PROBABILITY){
//      next = invert(currentGen[selecter]);
//    }else{
//      next = mutate(currentGen[selecter]);
//    }
    nextGen[i] = next;
  }
  
  for(int i = 0; i < GEN_SIZE; i++){
    delete currentGen[i];
    currentGen[i] = NULL;
    
    currentGen[i] = nextGen[i];
    nextGen[i] = NULL;
  }
  
  for(int i = 0; i < GEN_SIZE; i++){
    currentGen[i]->run();
  }
  setElete();
  runFinished = true;
}

int testApp::roulette(){

  int scoreSum = 0;
  
  for(int i = 0; i < GEN_SIZE; i++){
    scoreSum += currentGen[i]->getScore() * currentGen[i]->getScore();
  }
  
  int dice = rand() % scoreSum;

  scoreSum = 0;
  for(int i = 0; i < GEN_SIZE; i++){
    scoreSum += currentGen[i]->getScore() * currentGen[i]->getScore();
    if(scoreSum > dice) return i;
  }
  
  return GEN_SIZE - 1;
}

Roomba * testApp::crossover(Roomba * parent, Roomba * partner){
  Roomba * next = new Roomba();
  next->setField(&field);
  parent->getDNA()->copy(next->getDNA());

//  parent->getDNA()->printTree();
//  partner->getDNA()->printTree();
  
  Node ** n0 = next->getDNA()->selectRandomNodeByDepth();
  Node ** n1 = partner->getDNA()->selectRandomNodeByDepth();
  
  delete (*n0);
  (*n0) = (*n1)->copy();

//  next->getDNA()->printTree();
  
  return next;
}
Roomba * testApp::invert(Roomba * parent){
  Roomba * next = new Roomba();
  next->setField(&field);
  
  
  
  return next;
}
Roomba * testApp::mutate(Roomba * parent){
  Roomba * next = new Roomba();
  next->setField(&field);
  
  
  
  return next;
}

void testApp::setElete(){
  for(int i = 0; i < ELETE_SIZE; i++){
    elete[i] = NULL;
  }
  
  for(int i = 0; i < GEN_SIZE; i++){
    Roomba * r = currentGen[i];
    for(int j = 0; j < ELETE_SIZE; j++){
      if((elete[j] == NULL)||(r->getScore() > elete[j]->getScore())){
        Roomba * tmp = elete[j];
        elete[j] = r;
        r = tmp;
      }
    }
  }
}



















