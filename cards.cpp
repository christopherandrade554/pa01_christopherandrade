//Christopher Andrade Perm: 5698618
// 2/28/2022
#include "cards.h"

#include <iostream>

using namespace std;

Deck::Deck(): root(nullptr) {}

Deck::~Deck() {
  clear(root);
}

void Deck::clear(Node * n) {
  if (n) {
    clear(n -> left);
    clear(n -> right);
    delete n;
  }
}

bool Deck::insert(Select value) {
  if (!root) {
    root = new Node(value);
    return true;
  }
  return insert(value, root);
}

bool Deck::insert(Select value, Node * n) {
  if (value == n -> data)
    return false;
  if (value < n -> data) {
    if (n -> left)
      return insert(value, n -> left);
    else {
      n -> left = new Node(value);
      n -> left -> parent = n;
      return true;
    }
  } else {
    if (n -> right)
      return insert(value, n -> right);
    else {
      n -> right = new Node(value);
      n -> right -> parent = n;
      return true;
    }
  }
}

void Deck::sort() const {
  sort(root);
}
void Deck::sort(Node * n) const {
  if (!n) return;
  sort(n -> left);
  n -> data.printSelect();
  sort(n -> right);
}

Deck::Node * Deck::getNodeFor(Select value, Node * n) const {
  while (n) {
    if (n -> data == value) {
      return n;
    } else if (value < n -> data) {
      n = n -> left;
    } else {
      n = n -> right;
    }
  }
  return nullptr;
}

bool Deck::contains(Select value) const {
  Node * n = getNodeFor(value, root);
  if (!n) {
    return false;
  } else {
    return true;
  }
}

Deck::Node * Deck::getPredecessorNode(Select value) const {
  Node * n = getNodeFor(value, root);
  if (!n) {
    return nullptr;
  }
  if (n -> left) {
    n = n -> left;
    while (n -> right) {
      n = n -> right;
    }
    return n;
  } else {
    while (n -> parent != nullptr) {
      n = n -> parent;
      if (n -> data < value) {
        return n;
      }
    }
  }
  return nullptr;
}

Select Deck::getPredecessor(Select value) const {
  Node * n = getPredecessorNode(value);
  Select Select(0, 0);
  if (n == nullptr)
    return Select;
  return n -> data;
}

Deck::Node * Deck::getSuccessorNode(Select value) const {
  Node * n = getNodeFor(value, root);
  if (!n) {
    return nullptr;
  }
  if (n -> right) {
    n = n -> right;
    while (n -> left) {
      n = n -> left;
    }
    return n;
  } else {
    while (n -> parent) {
      n = n -> parent;
      if (n -> data > value) {
        return n;
      }
    }
  }
  return nullptr;
}

Select Deck::getSuccessor(Select value) const {
  Node * n = getSuccessorNode(value);
  Select select(0, 0);
  if (n == nullptr)

    return select;
  return n -> data;
}

bool Deck::remove(Select value) {
  Node * parent = nullptr;
  Node * current = root;
  while (current) {
    if (current -> data == value) {
      if (current -> left == nullptr && current -> right == nullptr) {
        if (parent == nullptr) {
          root = nullptr;
        } else if (parent -> left == current) {
          parent -> left = nullptr;
        } else {
          parent -> right = nullptr;
        }
        delete current;
        return true;
      } else if (current -> left && current -> right == nullptr) {
        if (parent == nullptr) {
          root = current -> left;
        } else if (parent -> left == current) {
          parent -> left = current -> left;
          current -> left -> parent = parent;
        } else {
          parent -> right = current -> left;
          current -> left -> parent = parent;
        }
        delete current;
        return true;
      } else if (current -> left == nullptr && current -> right) {
        if (parent == nullptr) {
          root = current -> right;
        } else if (parent -> left == current) {
          parent -> left = current -> right;
          current -> right -> parent = parent;
        } else {
          parent -> right = current -> right;
          current -> right -> parent = parent;
        }
        delete current;
        return true;
      } else {
        Node * successor = current -> right;
        while (successor -> left) {
          successor = successor -> left;
        }
        current -> data = successor -> data;
        parent = current;
        current = current -> right;
        value = successor -> data;
      }
    } else if (current -> data < value) {
      parent = current;
      current = current -> right;
    } else {
      parent = current;
      current = current -> left;
    }
  }
  return false;
}

Select Deck::getMin() const {
  Node * current = root;
  while (current -> left) {
    current = current -> left;
  }
  return current -> data;
}

Select Deck::getMax() const {
  Node * current = root;
  while (current -> right) {
    current = current -> right;
  }
  return current -> data;
}