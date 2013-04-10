//
//  arrow.h
//  ParticleSystem
//
//  Created by 村上 晋太郎 on 2013/04/06.
//
//

#ifndef __ParticleSystem__arrow__
#define __ParticleSystem__arrow__

#include <iostream>
#include "ofMain.h"

class Arrow {
private:
  float tri_a;
  float tri_b;
  float body_a;
  float body_b;

public:
  Arrow();
  void draw();

  float xFrom;
  float yFrom;
  float xTo;
  float yTo;
  
};

#endif /* defined(__ParticleSystem__arrow__) */
