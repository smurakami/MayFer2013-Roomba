//
//  ball.h
//  ParticleSystem
//
//  Created by 村上 晋太郎 on 2013/04/06.
//
//

#ifndef __ParticleSystem__ball__
#define __ParticleSystem__ball__

#include <iostream>
#include "ofMain.h"
#include "arrow.h"

class Ball {
public:
  Ball();

  float yForDraw();
  float xForDraw();
  void draw();

  //座標、向き
  float x;
  float y;
  float theta;
  //変化量
  float vx;
  float vy;
  float omega;
  ofColor color;
  Arrow arrow;
};


#endif /* defined(__ParticleSystem__ball__) */
