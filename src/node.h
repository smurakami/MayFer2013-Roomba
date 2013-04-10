//
//  node.h
//  Roomba
//
//  Created by 村上 晋太郎 on 2013/04/08.
//
//

#ifndef __Roomba__node__
#define __Roomba__node__

#include <iostream>
#include "sensor.h"

//
//Nodeのタイプは以下の五つである。
//randnum 乱数を返す。初期化や突然変異の際に一度だけ
//        生成される乱数であり、生成後は定数となる。
//sensor  赤外線センサーの出力値を返す
//move    回転角を第一引数、車輪速度を第二引数にして、
//        第三匹数の時間だけ移動する。(引数はそれぞれ正規化される。)
//        0を返す。
//iflte   第一引数と第二引数の値を比較して、
//        第一引数の方が小さければ第三匹数を、
//        それ以外では第四匹数を返す。
//prog2   第一引数、第二引数を順に実行して、第二引数を返す。
//
//

#define MAX_CHILD 4

typedef enum{
  RANDNUM = 0,
  SENSOR  = 1,
  MOVE    = 2,
  IFLTE   = 3,
  PROG2   = 4
} NodeType;

class Node {
private:
  NodeType nodeType;
  int val;
  int sizeOfSubTree;
  Node * childs[MAX_CHILD];
  Node * parent;
public:
  Node();
//-----------------------------
  int setRandomTerm();
  void setParent(Node * n);
//-----------------------------
  NodeType getNodeType();
  int getVal();
  int getSizeOfSubTree();
  Node * getChild(int i);
  Node * getParent();
//-----------------------------
  void printNode(int depth);
//-----------------------------
};


#endif /* defined(__Roomba__node__) */
