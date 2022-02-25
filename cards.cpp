// Christopher Andrade Perm:5698618
//Date 2/24/222
#include <iostream>

#include "cards.h"

using namespace std;

Deck::Deck(): root(nullptr) {}

Deck::~Deck() {
  clear(root);
}

void Deck::insert(cardsInDeck c) {
  if (!root) {
    root = new Node(c);
    return;
  } else {
    return insert(c, root);
  }
}

void Deck::insert(cardsInDeck c, Node * p) {
  if (p -> card == c)
    return;
  else if (c > p -> card) {
    if (p -> right)
      insert(c, p -> right);
    else {
      p -> right = new Node(c);
      p -> right -> parent = p;
      return;
    }
  } else {
    if (p -> left)
      insert(c, p -> left);
    else {
      p -> left = new Node(c);
      p -> left -> parent = p;
      return;
    }
  }
}

void Deck::remove(cardsInDeck c) {
  Node * p = locate(c, this -> root);
  if (!p) {
    return;
  }

  Node * parent = p -> parent;

  if (!p -> left && !p -> right) {

    if (p != root) {
      if (parent -> right == p) {

        parent -> right = nullptr;
        p = nullptr;
      } else {
        parent -> left = nullptr;
        p = nullptr;
      }
    } else {
      root = nullptr;
    }
    delete p;
  } else if (p -> left && p -> right) {

    Node * replace = p -> right;

    parent = nullptr;

    while (replace -> left) {

      parent = replace;
      replace = replace -> left;
    }

    if (parent) {
      parent -> left = replace -> right;
    } else {
      p -> right = replace -> right;
    }

    p -> card = replace -> card;

    replace = nullptr;
    free(replace);
  } else {

    Node * replace;

    if (!p -> left) {

      replace = p -> right;
    } else
      replace = p -> left;

    if (root == p) {
      root = replace;
      root -> parent = nullptr;
    } else {
      if (p == parent -> left) {
        parent -> left = replace;
      } else
        parent -> right = replace;
    }

    p = nullptr;
    delete p;
  }
  return;
}

bool Deck::contains(cardsInDeck c) {
  if (this -> locate(c, this -> root) == nullptr)
    return false;
  else
    return true;
}

void Deck::printInOrder() {
  printInOrder(this -> root);
}

void Deck::printInOrder(Node * root) {
  if (root) {
    printInOrder(root -> left);
    cout << root -> card.getSuit() << " " << root -> card.getValue() << endl;
    printInOrder(root -> right);
  }
}

Deck::Node * Deck::getSuccessorNode(cardsInDeck c) {

  Node * p = this -> locate(c, this -> root);

  if (!p) {
    return nullptr;
  } else {
    if (!p -> parent && !p -> right) {
      return nullptr;
    }

    if (!p -> right && p -> parent -> right == p && p -> card > root -> card && p -> card == this -> Max()) {
      return nullptr;
    }

    if (p -> right) {
      p = p -> right;
      while (p -> left) {
        p = p -> left;
      }
      return p;
    } else if (p -> parent -> left == p) {
      return p -> parent;
    } else {
      Node * n = p -> parent;
      while (p -> card > n -> card) {
        n = n -> parent;
      }
      return n;
    }
  }
}

cardsInDeck Deck::getSuccessor(cardsInDeck c) {
  Node * p = getSuccessorNode(c);
  cardsInDeck x;
  if (!p) {
    return x;
  } else
    return p -> card;
}

Deck::Node * Deck::getPredecessorNode(cardsInDeck c) {
  Node * p = this -> locate(c, this -> root);
  if (!p) {
    return nullptr;
  } else {
    if (!p -> parent && !p -> left) {
      return nullptr;
    }
    if (!p -> left && p -> parent -> left == p && p -> card < root -> card && p -> card == this -> Min()) {
      return nullptr;
    }

    if (p -> left) {
      p = p -> left;
      while (p -> right) {
        p = p -> right;
      }
      return p;
    } else if (p -> parent -> right == p) {
      return p -> parent;
    } else {
      Node * n = p -> parent;
      while (p -> card < n -> card) {
        n = n -> parent;
      }
      return n;
    }
  }
}

cardsInDeck Deck::getPredecessor(cardsInDeck c) {
  Node * p = this -> getPredecessorNode(c);
  cardsInDeck x;
  if (!p) {
    return x;
  } else
    return p -> card;
}

Deck::Node * Deck::locate(cardsInDeck c, Node * p) {

  Node * n = this -> root;
  while (n) {

    if (c == n -> card) {
      return n;
    } else if (c > n -> card) {

      n = n -> right;
    } else if (c < n -> card) {

      n = n -> left;
    }
  }
  return nullptr;
}

void Deck::clear(Node * root) {
  if (root) {
    clear(root -> left);
    clear(root -> right);
    delete root;
  }
}

Deck::Node * Deck::smNode() {
  Node * p = this -> root;
  while (p && p -> left) {
    p = p -> left;
  }
  return p;
}

cardsInDeck Deck::Min() {
  Node * p = smNode();
  return p -> card;
}

Deck::Node * Deck::bgNode() {
  Node * p = this -> root;
  while (p && p -> right) {
    p = p -> right;
  }
  return p;
}
cardsInDeck Deck::Max() {
  Node * p = bgNode();
  return p -> card;
}
