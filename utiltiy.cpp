#include <iostream>
#include "utility.h" 

tree::tree() : root(0) { }

bool tree::insert(int value) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(value);
	return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool tree::insert(int value, Node *n) {
    if (value == n->info)
	return false;
    if (value < n->info) {
	if (n->left)
	    return insert(value, n->left);
	else {
	    n->left = new Node(value);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if (n->right)
	    return insert(value, n->right);
	else {
	    n->right = new Node(value);
	    n->right->parent = n;
	    return true;
	}
    }
}

tree::Node* tree::find(int value, Node* n) const{
    while(n) {
            if (n->info == value){
                return n;
        }
        else if (value < n->info) {
            n = n->left;
        }
        else {
            n = n->right;
        }
    }
    return nullptr;
}


tree::Node* tree::getSuccessorNode(int value) const{
    Node* n = getNodeFor(value, root);
    if (n->right) { // first case
        n = n->right;
        while (n->left) {
            n = n->left;
        }
        return n;
    }
    else { // second case
        while (n->parent) {
            n = n->parent;
            if (n->info > value) {
                return n;
            }
        }
    }
    return nullptr;
}

// returns the successor value of the given value or 0 if there is none
int tree::successor(int value) const{
    Node* n = getSuccessorNode(value);
    if (n == nullptr)
        return 0;
    return n->info;
}


tree::Node* tree::getPredecessorNode(int value) const{
    Node* n = getNodeFor(value, root);
    if (!n) {
        return nullptr;
    }
    if(n->left) { // first case
        n = n-> left;
        while(n->right){
            n = n -> right;
        }
        return n;
    }
    else { // second case
        while (n->parent != nullptr) {
            n = n->parent;
            if (n->info < value) {
                return n;
            }
        }
    } 
    return nullptr;
}


// returns the predecessor value of the given value or 0 if there is none
int tree::getPredecessor(int value) const{
  Node* n = getPredecessorNode(value);
  if (n == nullptr)
    return 0;
  return n->info;
}