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
  void insert(Cards c);
  void remove(Cards c);
  bool contains(Cards c);
  void printInOrder();
  Cards getSuccessor(Cards c);
  Cards getPredecessor(Cards c);
  Cards findMin();
  Cards findMax();

  private:
    struct Node {
      Node * left, * right, * parent;
      Cards card;
      Node(Cards c1) {
        card = c1;
        left = right = parent = nullptr;
      }
    };

  Node * root;


  Node * findNode(Cards c, Node * p);
  Node * getSuccessorNode(Cards c);
  Node * getPredecessorNode(Cards c);
  Node * smNode();
  Node * bgNode();
  void printInOrder(Node * root);
  void insert(Cards c, Node * p);
  void clear(Node * root);
};

#endif