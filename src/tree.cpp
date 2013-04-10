//
//  tree.cpp
//  Roomba
//
//  Created by 村上 晋太郎 on 2013/04/07.
//
//

#include "tree.h"

Tree::Tree(){
  root = NULL;
}

void Tree::setRoot(){
  root = new Node();
}

int Tree::setRandomTerm(){
  if(root == NULL) setRoot();
  return root->setRandomTerm();
}

Node * Tree::getRoot(){
  return root;
}

void Tree::printTree(){
  using namespace std;
  cout << "---------PRINT TREE---------";
  root->printNode(0);
  cout << endl;
  cout << "----------END TREE----------" << endl;
}


