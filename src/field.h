//
//  field.h
//  Roomba
//
//  Created by 村上 晋太郎 on 2013/04/09.
//
//

#ifndef __Roomba__field__
#define __Roomba__field__

#include <iostream>
#include "ofMain.h"

#define FIELD_HEIGHT 12
#define FIELD_WIDTH  12
#define BLOCK_SIZE 60
#define HALF_BLOCK_SIZE (BLOCK_SIZE / 2)

typedef struct _Block{
  int x;
  int y;
} Block;

class Field {
public:
  char map[FIELD_HEIGHT][FIELD_WIDTH];
  Field();
  void draw();
  Block pointToBlock(float x, float y);

};

#endif /* defined(__Roomba__field__) */
