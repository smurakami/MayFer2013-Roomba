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
  //rootが確実にMOVEになるようにする
  root->setMoveNode(root);
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

void Tree::copy(Tree * t){
  t->root = root->copy();
}

Node ** Tree::selectRandomNodeByDepth(){
  return root->selectRandomNodeByDepth(1, root);
}