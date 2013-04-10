//
//  roomba.h
//  Roomba
//
//  Created by 村上 晋太郎 on 2013/04/06.
//
//

#ifndef __Roomba__roomba__
#define __Roomba__roomba__

#include <iostream>
#include "ball.h"
#include "tree.h"
#include "field.h"
#include "sensor.h"

#define FIELD_HEIGHT 12
#define FIELD_WIDTH 12

class Roomba {
private:
  char dustField[FIELD_HEIGHT][FIELD_WIDTH];
  Tree DNA;
  Field * field;
  Sensor sensor;
public:
  Ball body;
  Roomba();
  void setField(Field * p);
  void setSensorVal();
  void draw();
  void setRandomDNABySize(int size);
};

#endif /* defined(__Roomba__roomba__) */
