//
//  sensor.cpp
//  openFrameworksLib
//
//  Created by 村上 晋太郎 on 2013/04/09.
//
//

#include "sensor.h"

Sensor::Sensor(){
  for(int i = 0; i < SENSOR_NUM; i++){
    val[i] = 0;
  }
}

void Sensor::setField(Field * p){
  field = p;
}

float cot(float x){
  if((x == M_PI_2) || (x == M_PI_2 * 3)) return 0;
  else return (1.0 / tan(x));
}

void Sensor::setVal(float roombaX, float roombaY, float roombaTheta){
  std::cout << "roomba: " << roombaX << ", " << roombaY << std::endl;
  float theta;
  float x;
  float y;
  
  // 0:前 1:右 2:うしろ 3:左
  float wallX[4];
  float wallY[4];
  //前方の壁の傾き
  float wallTheta;
  
  theta = roombaTheta;
  
//  x = tan(theta)*(y - roombaY) + roombaX;
//  y = tan(theta)*(x - roombaX) + roombaY;
//  この2式をもとに、センサーとブロック境界の交点を求めていく。

  //前後のセンサー
  
  for(x = ceil(roombaX); x < BLOCK_SIZE * FIELD_WIDTH - HALF_BLOCK_SIZE; x += BLOCK_SIZE){
    if((theta == M_PI_2) || (theta == M_PI_2 * 3)) break;
    y = tan(theta)*(x - roombaX) + roombaY;
    if((y < 0)||(y > BLOCK_SIZE * FIELD_HEIGHT)) break;
    Block block = field->pointToBlock(x + HALF_BLOCK_SIZE, y);
    if(field->map[block.y][block.x] == 1){
      //      std::cout << "(" << x << ", " << y << ")" << std::endl;
      break;
      //      std::cout << "(" << block.x << ", " << block.y << ")" << std::endl;
    }
  }
  
  if(((0 <= theta) && (theta < M_PI_2)) ||
     ((M_PI_2 * 3 <= theta)&&(theta < M_PI * 2))){
    wallX[0] = x;
    wallY[0] = y;
    wallTheta = theta + M_PI_2;
    if(wallTheta >= M_PI * 2) wallTheta -= M_PI * 2;
  }else{
    wallX[2] = x;
    wallY[2] = y;
  }
  
  for(x = floor(roombaX); x > HALF_BLOCK_SIZE; x -= BLOCK_SIZE) {
    if((theta == M_PI_2) || (theta == M_PI_2 * 3)) break;
    y = tan(theta)*(x - roombaX) + roombaY;
    if((y < 0)||(y > BLOCK_SIZE * FIELD_HEIGHT)) break;
    Block block = field->pointToBlock(x - HALF_BLOCK_SIZE, y);
    if(field->map[block.y][block.x] == 1){
      //      std::cout << "(" << x << ", " << y << ")" << std::endl;
      break;
      //      std::cout << "(" << block.x << ", " << block.y << ")" << std::endl;
    }
  }
  
  if(((0 <= theta) && (theta < M_PI_2)) ||
     ((M_PI_2 * 3 <= theta)&&(theta < M_PI * 2))){
    wallX[2] = x;
    wallY[2] = y;
  }else{
    wallX[0] = x;
    wallY[0] = y;
    wallTheta = theta - M_PI_2;
  }
  
  
  for(y = ceil(roombaY); y < BLOCK_SIZE * FIELD_HEIGHT - HALF_BLOCK_SIZE; y += BLOCK_SIZE){
    if((theta == 0) || (theta == M_PI)) break;
    x = cot(theta)*(y - roombaY) + roombaX;
    if((x < 0)||(x > BLOCK_SIZE * FIELD_WIDTH)) break;
    Block block = field->pointToBlock(x, y + HALF_BLOCK_SIZE);
    if(field->map[block.y][block.x] == 1){
      //      std::cout << "(" << x << ", " << y << ")" << std::endl;
      break;
      //      std::cout << "(" << block.x << ", " << block.y << ")" << std::endl;
    }
  }
  
  if(((0 <= theta) && (theta < M_PI))){
    if(y < wallY[0]){
      wallX[0] = x;
      wallY[0] = y;
      wallTheta = theta;
    }
  }else{
    if(y < wallY[2]){
      wallX[2] = x;
      wallY[2] = y;
    }
  }
  
  
  for(y = floor(roombaY); y > HALF_BLOCK_SIZE; y -= BLOCK_SIZE){
    if((theta == 0) || (theta == M_PI)) break;
    x = cot(theta)*(y - roombaY) + roombaX;
    if((x < 0)||(x > BLOCK_SIZE * FIELD_WIDTH)) break;
    Block block = field->pointToBlock(x, y - HALF_BLOCK_SIZE);
    if(field->map[block.y][block.x] == 1){
      break;
      //      std::cout << "(" << x << ", " << y << ")" << std::endl;
      //      std::cout << "(" << block.x << ", " << block.y << ")" << std::endl;
    }
  }
  
  if(((0 <= theta) && (theta < M_PI))){
    if(y > wallY[2]){
      wallX[2] = x;
      wallY[2] = y;
    }
  }else{
    if(y > wallY[0]){
      wallX[0] = x;
      wallY[0] = y;
      wallTheta = theta - M_PI;
    }
  }
  
  //左右のセンサー
  theta += M_PI_2;
  if(theta >= M_PI * 2) theta -= M_PI * 2;
  
  for(x = ceil(roombaX); x < BLOCK_SIZE * FIELD_WIDTH - HALF_BLOCK_SIZE; x += BLOCK_SIZE){
    if((theta == M_PI_2) || (theta == M_PI_2 * 3)) break;
    y = tan(theta)*(x - roombaX) + roombaY;
    if((y < 0)||(y > BLOCK_SIZE * FIELD_HEIGHT)) break;
    Block block = field->pointToBlock(x + HALF_BLOCK_SIZE, y);
    if(field->map[block.y][block.x] == 1){
      //      std::cout << "(" << x << ", " << y << ")" << std::endl;
      break;
      //      std::cout << "(" << block.x << ", " << block.y << ")" << std::endl;
    }
  }
  
  if(((0 <= theta) && (theta < M_PI_2)) ||
     ((M_PI_2 * 3 <= theta)&&(theta < M_PI * 2))){
    wallX[1] = x;
    wallY[1] = y;
  }else{
    wallX[3] = x;
    wallY[3] = y;
  }
  
  for(x = floor(roombaX); x > HALF_BLOCK_SIZE; x -= BLOCK_SIZE) {
    if((theta == M_PI_2) || (theta == M_PI_2 * 3)) break;
    y = tan(theta)*(x - roombaX) + roombaY;
    if((y < 0)||(y > BLOCK_SIZE * FIELD_HEIGHT)) break;
    Block block = field->pointToBlock(x - HALF_BLOCK_SIZE, y);
    if(field->map[block.y][block.x] == 1){
      //      std::cout << "(" << x << ", " << y << ")" << std::endl;
      break;
      //      std::cout << "(" << block.x << ", " << block.y << ")" << std::endl;
    }
  }
  
  if(((0 <= theta) && (theta < M_PI_2)) ||
     ((M_PI_2 * 3 <= theta)&&(theta < M_PI * 2))){
    wallX[3] = x;
    wallY[3] = y;
  }else{
    wallX[1] = x;
    wallY[1] = y;
  }
  
  
  for(y = ceil(roombaY); y < BLOCK_SIZE * FIELD_HEIGHT - HALF_BLOCK_SIZE; y += BLOCK_SIZE){
    if((theta == 0) || (theta == M_PI)) break;
    x = cot(theta)*(y - roombaY) + roombaX;
    if((x < 0)||(x > BLOCK_SIZE * FIELD_WIDTH)) break;
    Block block = field->pointToBlock(x, y + HALF_BLOCK_SIZE);
    if(field->map[block.y][block.x] == 1){
      //      std::cout << "(" << x << ", " << y << ")" << std::endl;
      break;
      //      std::cout << "(" << block.x << ", " << block.y << ")" << std::endl;
    }
  }
  
  if(((0 <= theta) && (theta < M_PI))){
    if(y < wallY[1]){
      wallX[1] = x;
      wallY[1] = y;
    }
  }else{
    if(y < wallY[3]){
      wallX[3] = x;
      wallY[3] = y;
    }
  }
  
  
  for(y = floor(roombaY); y > HALF_BLOCK_SIZE; y -= BLOCK_SIZE){
    if((theta == 0) || (theta == M_PI)) break;
    x = cot(theta)*(y - roombaY) + roombaX;
    if((x < 0)||(x > BLOCK_SIZE * FIELD_WIDTH)) break;
    Block block = field->pointToBlock(x, y - HALF_BLOCK_SIZE);
    if(field->map[block.y][block.x] == 1){
      break;
      //      std::cout << "(" << x << ", " << y << ")" << std::endl;
      //      std::cout << "(" << block.x << ", " << block.y << ")" << std::endl;
    }
  }
  
  if(((0 <= theta) && (theta < M_PI))){
    if(y > wallY[3]){
      wallX[3] = x;
      wallY[3] = y;
    }
  }else{
    if(y > wallY[1]){
      wallX[1] = x;
      wallY[1] = y;
    }
  }
  
  for(int i = 0; i < 4; i++){
    val[i] = ofDist(roombaX, roombaY, wallX[i], wallY[i]);
  }
  val[4] = wallTheta * 180 / M_PI;
  
//  std::cout << "front wall: " << wallX[0] << ", " << wallY[0] << std::endl;
//  std::cout << "back  wall: " << wallX[2] << ", " << wallY[2] << std::endl;
//  std::cout << "right wall: " << wallX[1] << ", " << wallY[1] << std::endl;
//  std::cout << "left  wall: " << wallX[3] << ", " << wallY[3] << std::endl;
//  std::cout << "wall theta: " << wallTheta * 180 / M_PI << std::endl;
  
  for(int i = 0; i < 5; i++){
    std::cout << "sensor.val[" << i << "] = " << val[i] << endl;
  }

}