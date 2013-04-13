//
//  path.h
//  Roomba
//
//  Created by 村上 晋太郎 on 2013/04/10.
//
//

#ifndef __Roomba__path__
#define __Roomba__path__

#include <iostream>
#include <list>
#include "ofMain.h"
#include "field.h"

typedef struct _Position{
  float x;
  float y;  
} Position;

class Path {
public:
  ofColor color;
  std::list<Position> p;  
  Path();
  void push(float x, float y);
  void clear();
  void draw();
  float xForDraw(float x);
  float yForDraw(float y);
};


#endif /* defined(__Roomba__path__) */

