//Christopher Andrade
#ifndef CARDS_H
#define CARDS_H

#include <iostream>

#include <unordered_map>

#include "utility.h"

using namespace std;

class Deck {
  public:
    Deck();
  ~Deck();
  void insert(Selected c);
  void remove(Selected c);
  bool contains(Selected c);
  void Print();
  Selected Successor(Selected c);
  Selected Predecessor(Selected c);
  Selected Min();
  Selected Max();

  private:
    struct Node {
      Node * left, * right, * parent;
      Selected card;
      Node(Selected c1) {
        card = c1;
        left = right = parent = nullptr;
      }
    };

  Node * root;

    void Print(Node * root);
  void insert(Selected c, Node * p);
  void clear(Node * root);
  Node * findNode(Selected c, Node * p);
  Node * SuccessorNode(Selected c);
  Node * PredecessorNode(Selected c);
  Node * smNode();
  Node * bgNode();

};

#endif