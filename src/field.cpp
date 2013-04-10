//
//  field.cpp
//  Roomba
//
//  Created by 村上 晋太郎 on 2013/04/09.
//
//

#include "field.h"

const char ORIGIN_OF_FIELD[][FIELD_WIDTH] = {
  
  {1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1}
  
};


Field::Field(){
  for(int i = 0; i < FIELD_HEIGHT; i++){
    for (int j = 0; j < FIELD_WIDTH; j++) {
      map[i][j] = ORIGIN_OF_FIELD[i][j];
    }
  }
}

void Field::draw(){
  ofSetLineWidth(1);
  ofNoFill();
  ofSetColor(0,255, 100);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofRect(ofGetWindowWidth()/2, ofGetWindowHeight()/2, BLOCK_SIZE * FIELD_WIDTH, BLOCK_SIZE * FIELD_HEIGHT);
  int xStart = ofGetWindowWidth() / 2 -  HALF_BLOCK_SIZE * FIELD_WIDTH;
  int yStart = ofGetWindowHeight() / 2 - HALF_BLOCK_SIZE * FIELD_HEIGHT;
  ofSetRectMode(OF_RECTMODE_CORNER);
  for (int i = 0; i < FIELD_HEIGHT; i++) {
    for (int j = 0; j < FIELD_WIDTH; j++) {
      if(map[i][j] == 1) ofFill();
      else ofNoFill();
      ofRect(xStart + BLOCK_SIZE * i, yStart + BLOCK_SIZE * j, BLOCK_SIZE, BLOCK_SIZE);
    }
  }
}

Block Field::pointToBlock(float x, float y){
  Block block;
  block.x = (int)(x / BLOCK_SIZE);
  block.y = (int)(y / BLOCK_SIZE);
  return block;
}
