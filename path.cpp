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