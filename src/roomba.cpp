//
//  roomba.cpp
//  Roomba
//
//  Created by 村上 晋太郎 on 2013/04/06.
//
//

#include "roomba.h"
#include "field.h"
#include <list>

Roomba::Roomba(){
  body.x = BLOCK_SIZE * FIELD_WIDTH  / 2;
  body.y = BLOCK_SIZE * FIELD_HEIGHT / 2;
  setRandomDNABySize(16);
  DNA.printTree();
  
//  for(int i = 0; i < 10; i++){
//    path.push(0.1 * i, 10*i);
//  }
//  
//  std::list<Position>::iterator itr;
//  
//  for(itr = path.p.begin(); itr != path.p.end(); itr++){
//    cout << "x = " << itr->x << ", y = " << itr->y << endl;
//  }
  
}

void Roomba::setField(Field * p){
  field = p;
  sensor.setField(p);
}

void Roomba::setSensorVal(){
  sensor.setVal(body.x, body.y, body.theta);
}

void Roomba::draw(){
  body.draw();
}

void Roomba::setRandomDNABySize(int size){
  DNA.setRoot();
  int addedSize = 0;
  while(addedSize < size){
    addedSize += DNA.setRandomTerm();
  }
}

void Roomba::run(){
  Node * root = DNA.getRoot();
  runNode(root);
}

int Roomba::runNode(Node * node){
  int val0, val1;
  switch(node->getNodeType()){
    case RANDNUM:
      return node->getVal();
    case SENSOR :
      return sensor.val[node->getVal()];
    case MOVE   :
//---------------------------------------
//      ここを書いたらルンバ本体は完成
//---------------------------------------
      break;
    case IFLTE  :
      val0 = runNode(node->getChild(0));
      val1 = runNode(node->getChild(1));
      if(val0 < val1) return runNode(node->getChild(2));
      else return runNode(node->getChild(3));
    case PROG2  :
      runNode(node->getChild(0));
      return runNode(node->getChild(1));
    default:
      break;
  }
  return 0;
}


