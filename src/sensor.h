//
//  sensor.h
//  openFrameworksLib
//
//  Created by 村上 晋太郎 on 2013/04/09.
//
//

#ifndef __openFrameworksLib__sensor__
#define __openFrameworksLib__sensor__

#include <iostream>
#define SENSOR_NUM 5
#include "field.h"

class Sensor {
  Field * field;
public:
  Sensor();
  void setField(Field * p);
  void setVal(float roombaX, float roombaY, float roombaTheta);
  float val[SENSOR_NUM];//センサーの取得値
};

#endif /* defined(__openFrameworksLib__sensor__) */
