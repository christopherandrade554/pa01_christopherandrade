#include <iostream>

#include "cards.h"

using namespace std;

CardsBST::CardsBST(): root(nullptr) {}

CardsBST::~CardsBST() {
  clear(root);
}

void CardsBST::insert(Cards c) {
  if (!root) {
    root = new cardNode(c);
    return;
  } else {
    return insert(c, root);
  }
}

void CardsBST::insert(Cards c, cardNode * p) {
  if (p -> card == c)
    return;
  else if (c > p -> card) {
    if (p -> right)
      insert(c, p -> right);
    else {
      p -> right = new cardNode(c);
      p -> right -> parent = p;
      return;
    }
  } else {
    if (p -> left)
      insert(c, p -> left);
    else {
      p -> left = new cardNode(c);
      p -> left -> parent = p;
      return;
    }
  }
}

void CardsBST::remove(Cards c) {

  cardNode * p = findNode(c, this -> root);

  if (!p) {
    return;
  }

  cardNode * parent = p -> parent;

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

    cardNode * replace = p -> right;
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

    cardNode * replace;

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

bool CardsBST::contains(Cards c) {
  if (this -> findNode(c, this -> root) == nullptr)
    return false;
  else
    return true;
}

void CardsBST::printInOrder() {
  printInOrder(this -> root);
}

void CardsBST::printInOrder(cardNode * root) {
  if (root) {
    printInOrder(root -> left);
    cout << root -> card.getSuit() << " " << root -> card.getVal() << endl;
    printInOrder(root -> right);
  }
}

CardsBST::cardNode * CardsBST::getSuccessorNode(Cards c) {

  cardNode * p = this -> findNode(c, this -> root);

  if (!p) {
    return nullptr;
  } else {
    if (!p -> parent && !p -> right) {
      return nullptr;
    }

    if (!p -> right && p -> parent -> right == p && p -> card > root -> card && p -> card == this -> findMax()) {
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
      cardNode * n = p -> parent;
      while (p -> card > n -> card) {
        n = n -> parent;
      }
      return n;
    }
  }
}

Cards CardsBST::getSuccessor(Cards c) {
  cardNode * p = getSuccessorNode(c);
  Cards x;
  if (!p) {
    return x;
  } else
    return p -> card;
}

CardsBST::cardNode * CardsBST::getPredecessorNode(Cards c) {
  cardNode * p = this -> findNode(c, this -> root);
  if (!p) {
    return nullptr;
  } else {
    if (!p -> parent && !p -> left) {
      return nullptr;
    }
    if (!p -> left && p -> parent -> left == p && p -> card < root -> card && p -> card == this -> findMin()) {
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
      cardNode * n = p -> parent;
      while (p -> card < n -> card) {
        n = n -> parent;
      }
      return n;
    }
  }
}

Cards CardsBST::getPredecessor(Cards c) {
  cardNode * p = this -> getPredecessorNode(c);
  Cards x;
  if (!p) {
    return x;
  } else
    return p -> card;
}

CardsBST::cardNode * CardsBST::findNode(Cards c, cardNode * p) {

  cardNode * n = this -> root;
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

void CardsBST::clear(cardNode * root) {
  if (root) {
    clear(root -> left);
    clear(root -> right);
    delete root;
  }
}

CardsBST::cardNode * CardsBST::minNode() {
  cardNode * p = this -> root;
  while (p && p -> left) {
    p = p -> left;
  }
  return p;
}

Cards CardsBST::findMin() {
  cardNode * p = minNode();
  return p -> card;
}

CardsBST::cardNode * CardsBST::maxNode() {
  cardNode * p = this -> root;
  while (p && p -> right) {
    p = p -> right;
  }
  return p;
}
Cards CardsBST::findMax() {
  cardNode * p = maxNode();
  return p -> card;
}