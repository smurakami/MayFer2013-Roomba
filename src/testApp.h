#pragma once

#include "ofMain.h"
#include "roomba.h"
#include "field.h"
#define GEN_SIZE 256
#define DEFAULT_TREE_SIZE 400 //400が最適?
//#define DEFAULT_TREE_SIZE 10 //400が最適?


#define MUTATION_PROBABILITY 3
#define INVERTION_PROBABILITY 27
#define CROSSOVER_PROBABILITY 70
#define MAX_PROBABILITY (MUTATION_PROBABILITY + INVERTION_PROBABILITY + CROSSOVER_PROBABILITY)

#define ELETE_SIZE 10

class testApp : public ofBaseApp{

public:
  void setup();
  void update();
  void draw();

  void keyPressed  (int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y );
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  
  void drawFieldFrame();
  
  Roomba * currentGen[GEN_SIZE];
  Roomba * nextGen[GEN_SIZE];
  
  Roomba * elete[ELETE_SIZE];
  void setElete();
  bool runFinished;
  
  Field field;
  
//--------------------------------------------------------------
//                         GP PROGRAM
//--------------------------------------------------------------
  int roulette();
  void stepGen();
  Roomba * crossover(Roomba * parent, Roomba * partner);
  Roomba * invert(Roomba * parent);
  Roomba * mutate(Roomba * parent);
};

