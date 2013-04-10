//
//  arrow.cpp
//  ParticleSystem
//
//  Created by 村上 晋太郎 on 2013/04/06.
//
//

#include "arrow.h"

Arrow::Arrow(){
  
}

void Arrow::draw(){
  ofSetColor(ofColor::red);
  ofSetLineWidth(2);
  ofLine(xFrom, yFrom, xTo, yTo);
  body_a = xTo - xFrom;
  body_b = yTo - yFrom;
  tri_a = 15 * (body_a / ofDist(0, 0, body_a, body_b));
  tri_b = 15 * (body_b / ofDist(0, 0, body_a, body_b));
  ofTriangle(xTo, yTo, xTo - tri_a - tri_b, yTo - tri_b + tri_a, xTo - tri_a + tri_b, yTo - tri_b - tri_a);
 
}