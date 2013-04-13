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
    nodeType = RANDNUM;
    val = rand() % 100;
  }else{
    nodeType = SENSOR;
    val = rand() % SENSOR_NUM;
  }
  sizeOfSubTree = 1;
  for(int i = 0; i < MAX_CHILD; i++){
    childs[i] = NULL;
    parent = NULL;
  }
}

//rootが確実にMOVEになるようにする
void Node::setMoveNode(Node * termNode){
  if((termNode->nodeType == MOVE) ||
     (termNode->nodeType == IFLTE) ||
     (termNode->nodeType == PROG2)){
    perror("Node::setMoveNode: not term Node\n");
    exit(1);
  }

  int nextChild;
  int addedSize;
  
  nodeType = MOVE;
  val = 0;
  addedSize = 3;
  sizeOfSubTree += addedSize;
  for(int i = 0; i < addedSize; i++){
    childs[i] = new Node();
    childs[i]->setParent(this);
  }
}

int Node::setRandomTerm(){
  int nextChild;
  int addedSize;
  switch (nodeType) {
    case RANDNUM:
    case SENSOR:
      switch (rand() % 3) {
        case 0:
          nodeType = MOVE;
          val = 0;
          addedSize = 3;
          break;
        case 1:
          nodeType = IFLTE;
          val = 0;
          addedSize = 4;
          break;
        case 2:
          nodeType = PROG2;
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
      
    case MOVE:
      nextChild = rand() % 3;
      break;
    case IFLTE:
      nextChild = rand() % 4;
      break;
    case PROG2:
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

NodeType Node::getNodeType(){
  return nodeType;
}

int Node::getVal(){
  return val;
}

int Node::getSizeOfSubTree(){
  return sizeOfSubTree;
}

Node * Node::getChild(int i){
  return childs[i];
}

Node * Node::getParent(){
  return parent;
}

void Node::printNode(int depth){
  using namespace std;
  switch (nodeType) {
    case SENSOR:
      cout << "S" << val;
      return;
    case RANDNUM:
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
    case MOVE:
      cout << "MOVE";
      for(int i = 0; i < 3; i++){
        cout << " ";
        childs[i]->printNode(depth + 1);
      }
      break;
    case IFLTE:
      cout << "IFLTE";
      for(int i = 0; i < 4; i++){
        cout << " ";
        childs[i]->printNode(depth + 1);
      }
      break;
    case PROG2:
      cout << "PROG2";
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

Node * Node::copy(){
  Node * n = new Node();
  n->nodeType = nodeType;
  n->val = val;
  n->sizeOfSubTree = sizeOfSubTree;
  int childNum;
  switch (nodeType) {
    case RANDNUM:
    case SENSOR:
      return n;
    case MOVE:
      childNum = 3;
      break;
    case IFLTE:
      childNum = 4;
      break;
    case PROG2:
      childNum = 2;
      break;
    default:
      break;
  }
  
  for(int i = 0; i < childNum; i++){
    n->childs[i] = childs[i]->copy();
  }
  
  return n;
}

int getProbabilityByDepth(int depth){
  int num = DENOMINATOR;
  //最低でも1
  for(int i = 1; i < 14; i++){
    num /= 2;
  }
  return num;
}

Node ** Node::selectRandomNodeByDepth(int depth, Node *root){
  int childNum;
  switch (nodeType) {
    case RANDNUM:
    case SENSOR:
      return root->selectRandomNodeByDepth(1, root);
    case MOVE:
      childNum = 3;
      break;
    case IFLTE:
      childNum = 4;
      break;
    case PROG2:
      childNum = 2;
      break;
    default:
      break;
  }
  
  int child = rand() % childNum;
  int dice = rand() % DENOMINATOR;
  if(dice < getProbabilityByDepth(depth)){
    return &childs[child];
  }
  
  return childs[child]->selectRandomNodeByDepth(depth + 1, root);
}
