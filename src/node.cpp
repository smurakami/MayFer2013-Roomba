//
//  node.cpp
//  Roomba
//
//  Created by 村上 晋太郎 on 2013/04/08.
//
//

#include "node.h"

Node::Node(){
  if(rand() % 2){
    nodeType = randnum;
    val = rand() % 100;
  }else{
    nodeType = sensor;
    val = rand() % SENSOR_NUM;
  }
  sizeOfSubTree = 1;
  for(int i = 0; i < MAX_CHILD; i++){
    childs[i] = NULL;
    parent = NULL;
  }
}

int Node::setRandomTerm(){
  int nextChild;
  int addedSize;
  switch (nodeType) {
    case randnum:
    case sensor:
      switch (rand() % 3) {
        case 0:
          nodeType = move;
          val = 0;
          addedSize = 3;
          break;
        case 1:
          nodeType = iflte;
          val = 0;
          addedSize = 4;
          break;
        case 2:
          nodeType = prog2;
          val = 0;
          addedSize = 2;
          break;
        default:
          break;
      }
      sizeOfSubTree += addedSize;
      for(int i = 0; i < addedSize; i++){
        childs[i] = new Node();
        childs[i]->setParent(this);
      }

      return addedSize;
      
    case move:
      nextChild = rand() % 3;
      break;
    case iflte:
      nextChild = rand() % 4;
      break;
    case prog2:
      nextChild = rand() % 2;
      break;
    default:
      break;
  }
  addedSize = childs[nextChild]->setRandomTerm();
  sizeOfSubTree += addedSize;
  return addedSize;
}

void Node::setParent(Node * n){
  parent = n;
}

void Node::printNode(int depth){
  using namespace std;
  switch (nodeType) {
    case sensor:
      cout << "S" << val;
      return;
    case randnum:
      cout << "R" << val;
      return;
    default:
      break;
  }
  cout << endl;
  for(int i = 0; i < depth; i++){
    cout << "  ";
  }
  cout << "(";
  switch (nodeType) {
    case move:
      cout << "move";
      for(int i = 0; i < 3; i++){
        cout << " ";
        childs[i]->printNode(depth + 1);
      }
      break;
    case iflte:
      cout << "iflte";
      for(int i = 0; i < 4; i++){
        cout << " ";
        childs[i]->printNode(depth + 1);
      }
      break;
    case prog2:
      cout << "prog2";
      for(int i = 0; i < 2; i++){
        cout << " ";
        childs[i]->printNode(depth + 1);
      }
      break;
    default:
      break;
  }
  cout << ")";
  
}
