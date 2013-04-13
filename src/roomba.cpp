//
//  roomba.cpp
//  Roomba
//
//  Created by 村上 晋太郎 on 2013/04/06.
//
//

#include "roomba.h"
#include "field.h"
#include <list>

Roomba::Roomba(){
  color.set(rand() % 256, rand() % 256, rand() % 256);
  time = 0.0;
  score = 0;
  finished = false;

  drawPath = true;
  drawRoomba = false;
  
  body.x = BLOCK_SIZE * FIELD_WIDTH  / 2;
  body.y = BLOCK_SIZE * FIELD_HEIGHT / 2;
  body.color = color;
  path.color = color;
  path.push(body.x, body.y);
  
}

void Roomba::setField(Field * p){
  field = p;
  sensor.setField(p);

  //ごみマップのコピー
  wholeDust = 0;
  for(int i = 0; i < FIELD_HEIGHT; i++){
    for(int j = 0; j < FIELD_WIDTH; j++){
      dustMap[i][j] = field->dustMap[i][j];
      wholeDust += dustMap[i][j];
    }
  }
}

void Roomba::setSensorVal(){
  sensor.setVal(body.x, body.y, body.theta);
}

void Roomba::draw(){
  if(drawRoomba) body.draw();
  if(drawPath) path.draw();
}

void Roomba::setRandomDNABySize(int size){
  DNA.setRoot();
  int addedSize = 0;
  while(addedSize < size){
    addedSize += DNA.setRandomTerm();
  }
}

void Roomba::run(){
  Node * root = DNA.getRoot();
  while(!finished){
    runNode(root);
  }
//  cout << "score: " << score << endl;
}

int Roomba::runNode(Node * node){
  if(finished) return 0;
  
  int val0, val1, val2;
  switch(node->getNodeType()){
    case RANDNUM:
      return node->getVal();

    case SENSOR :
      return sensor.val[node->getVal()];
    
    case MOVE   :
      val0 = runNode(node->getChild(0));
      val1 = runNode(node->getChild(1));
      val2 = runNode(node->getChild(2));
      move(val0, val1, val2);
      return 0;
    
    case IFLTE  :
      val0 = runNode(node->getChild(0));
      val1 = runNode(node->getChild(1));
      if(val0 < val1) return runNode(node->getChild(2));
      else return runNode(node->getChild(3));
    
    case PROG2  :
      runNode(node->getChild(0));
      return runNode(node->getChild(1));
    
    default:
      break;
  }
  return 0;
}

void Roomba::move(float val0, float val1, float val2){
  
  float rotation = val0;
  float speed = 30. + val0 * 30. /100.;
//  float speed = val1 * 60.0 / 100;
  float moveTime = (val2 + 1) / 100.0;
  
//  cout << "Roomba::move" << endl;
//  cout << "rotation = " << rotation
//  <<", speed = " << speed
//  << ", moveTime = " << moveTime << endl;
  
  if(finished) return;

  //必ず0.01秒は時間が進むようにする。
  moveTime += 0.01;
  
  for(int i = 0; i < moveTime * 100; i++){
    body.theta += rotation / 100;
    body.vx = speed * cos(body.theta) / 100;
    body.vy = speed * sin(body.theta) / 100;

    // 0.壁判定を作る
    Block block;
    block = field->pointToBlock(body.x + body.vx, body.y);
    if(field->map[block.y][block.x] == 1){
      body.vx = 0;
    }
    
    block = field->pointToBlock(body.x, body.y + body.vy);
    if(field->map[block.y][block.x] == 1){
      body.vy = 0;
    }
    
    //壁を判定できたら動かす
    body.x += body.vx;
    body.y += body.vy;
    
    // 1.時間を計る仕組みを作る
    time += 0.01;
    if(time > TIME_LIMIT){
      finished = true;
      return;
    }
    
    // 2.ごみ判定をつくる
    block = field->pointToBlock(body.x, body.y);
    int dust;
    if((dust = dustMap[block.y][block.x]) > 0){
      score += dust;
      dustMap[block.y][block.x] = 0;
      if(score == wholeDust){
        finished = true;
        score += (int)(TIME_LIMIT - time);
        return;
      }
    }
    
    
    // 3.runNodeからこの関数を呼び出すときに、値の正規化をするようにする。
    // ->完了
    
    //現在位置を経路にプッシュ。あとからdrawする。
    path.push(body.x, body.y);
    
    
  }
}

int Roomba::getScore(){
  return score;
}

Tree * Roomba::getDNA(){
  return &DNA;
}
