//
//  roomba.cpp
//  Roomba
//
//  Created by 村上 晋太郎 on 2013/04/06.
//
//

#include "roomba.h"
#include "field.h"

Roomba::Roomba(){
  body.x = BLOCK_SIZE * FIELD_WIDTH  / 2;
  body.y = BLOCK_SIZE * FIELD_HEIGHT / 2;
  body.theta = M_PI / 3;
  setRandomDNABySize(16);
  DNA.printTree();
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

