//
//  tree.h
//  Roomba
//
//  Created by 村上 晋太郎 on 2013/04/07.
//
//

#ifndef __Roomba__tree__
#define __Roomba__tree__

#include <iostream>
#include "node.h"

class Tree {
private:
  Node * root;
public:
  Tree();
  void setRoot();
  int setRandomTerm();
  void printTree();
};

#endif /* defined(__Roomba__tree__) */

















