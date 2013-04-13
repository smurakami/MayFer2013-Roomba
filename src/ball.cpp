//
//  ball.cpp
//  ParticleSystem
//
//  Created by 村上 晋太郎 on 2013/04/06.
//
//

#include "ball.h"
#include "field.h"

Ball::Ball(){
  color.set(rand() % 256, rand() % 256, rand() % 256);
  theta = M_PI_2 * 3;
}

float Ball::xForDraw(){
  return ofGetWindowWidth()/2 - HALF_BLOCK_SIZE * FIELD_WIDTH + x;
}

float Ball::yForDraw(){
  return ofGetWindowHeight()/2 - HALF_BLOCK_SIZE * FIELD_HEIGHT + y;
}

void Ball::draw(){
  ofSetColor(color);
  ofFill();
  ofCircle(xForDraw() ,yForDraw(), 30);
  
  ofLine(xForDraw() - cos(theta) * 1200, yForDraw() - sin(theta) * 1200, xForDraw() + cos(theta) * 1200, yForDraw() + sin(theta) * 1200);
  ofLine(xForDraw() - sin(theta) * 1200, yForDraw() + cos(theta) * 1200, xForDraw() + sin(theta) * 1200, yForDraw() - cos(theta) * 1200);
  
  arrow.xFrom = xForDraw();
  arrow.yFrom = yForDraw();
  arrow.xTo = xForDraw() + cos(theta) * 60;
  arrow.yTo = yForDraw() + sin(theta) * 60;
  arrow.draw();
  
  
}
