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
#include "path.h"

#define FIELD_HEIGHT 12
#define FIELD_WIDTH 12
#define TIME_LIMIT 300.0
//#define DEFAULT_TREE_SIZE 400

class Roomba {
private:
  char dustMap[FIELD_HEIGHT][FIELD_WIDTH];
  Tree DNA;
  Field * field;
  Sensor sensor;
  ofColor color;
  //性能シミュレーションに使う変数群
  float time;
  int score;
  int wholeDust;
  bool finished;
public:
  Path path;
  Ball body;
  Roomba();
  void setField(Field * p);
  
  // 描画するかのフラグ
  bool drawPath;
  bool drawRoomba;

  int getScore();
  Tree * getDNA();
  
  void setSensorVal();
  void setRandomDNABySize(int size);

  void draw();

  void run();
  int runNode(Node * node);
  void move(float val0, float val1, float val2);
};

#endif /* defined(__Roomba__roomba__) */
