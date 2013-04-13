//
//  path.cpp
//  Roomba
//
//  Created by 村上 晋太郎 on 2013/04/10.
//
//

#include "path.h"

Path::Path(){
}

void Path::push(float x, float y){
  Position pos = {x, y};
  p.push_back(pos);
}

void Path::draw(){
  ofSetColor(color);
  std::list<Position>::iterator i;
  i = p.begin();
  if(i == p.end()) return;
  int counter = 0;
  float prevX = i->x;
  float prevY = i->y;
  while(1){
    i++;
    if(i == p.end()) return;
    if(counter % 100 == 0){
      ofLine(xForDraw(prevX), yForDraw(prevY), xForDraw(i->x), yForDraw(i->y));
      prevX = i->x;
      prevY = i->y;
    }
    counter++;
  }
}

float Path::xForDraw(float x){
  return ofGetWindowWidth()/2 - HALF_BLOCK_SIZE * FIELD_WIDTH + x;
}

float Path::yForDraw(float y){
  return ofGetWindowHeight()/2 - HALF_BLOCK_SIZE * FIELD_HEIGHT + y;
}
