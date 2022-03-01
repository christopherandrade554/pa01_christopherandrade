#ifndef CARDS_H
#define CARDS_H
#include "utility.h"

#include <iostream>

using namespace std;

class Deck {

  public:
    Deck();
  ~Deck();
  Select getMin() const;
  Select getMax() const;
  Select getPredecessor(Select value) const;
  Select getSuccessor(Select value) const;
  bool insert(Select value);
  void sort() const;
  bool contains(Select value) const;
  bool remove(Select value);

  private:

    struct Node {
      Node * left;
      Node * right;
      Node * parent;
      Select data;
      Node(Select c1) {
        data = c1;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
      }
    };
  Node * root;
  Node * getNodeFor(Select value, Node * n) const;
  Node * getSuccessorNode(Select value) const;
  Node * getPredecessorNode(Select value) const;
  void clear(Node * n);
  bool insert(Select value, Node * n);
  void sort(Node * n) const;


};
#endif