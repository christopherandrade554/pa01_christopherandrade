#ifndef CARDS_H
#define CARDS_H

#include <iostream>

#include <unordered_map>

#include "utility.h"

using namespace std;

class CardsBST {
  public:
    CardsBST();
  ~CardsBST();
  void insert(Cards c);
  void remove(Cards c);
  bool contains(Cards c);
  void printInOrder();
  Cards getSuccessor(Cards c);
  Cards getPredecessor(Cards c);
  Cards findMin();
  Cards findMax();

  private:
    struct cardNode {
      cardNode * left, * right, * parent;
      Cards card;
      cardNode(Cards c1) {
        card = c1;
        left = right = parent = nullptr;
      }
    };

  cardNode * root;


  cardNode * findNode(Cards c, cardNode * p);
  cardNode * getSuccessorNode(Cards c);
  cardNode * getPredecessorNode(Cards c);
  cardNode * minNode();
  cardNode * maxNode();
  void printInOrder(cardNode * root);
  void insert(Cards c, cardNode * p);
  void clear(cardNode * root);
};

#endif