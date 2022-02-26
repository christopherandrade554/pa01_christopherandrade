#include <iostream>
using namespace std;
#include <string>
#include "cards.h"

Card::Card(char x, char y) {
      suit = x;
      value = y;
      next = 0;
    }

bool Card::operator==(const Card& c) {
      // Testing value equality
      if (suit == c.suit && value == c.value) return true;
      return false;
    }
    
Hand::Hand() {
      first = 0;
      last = 0;
    }
    
int Hand::contains(Card* c) {
      int count = 0;
      Card* iter = first;
      while(iter) {
	count++;      
        if (*iter == *c) return count; // Returns location of the equal card
	iter = iter->next;
      }
      return 0;
    }
    
void Hand::remove(int x) {
      if (x == 0) return;  // base case
      if (x == 1) { // first node
	if (first == last) delete first;
	else {
	  Card* temp = first;
	  first = first->next;
	  delete temp;
	}
        return;
      }
      else {
	int count = 2;
        Card* iter = first;
	while(iter) { // iterate through
	  if (x == count) {
	    Card* temp = iter->next;
	    iter->next = iter->next->next;
	    delete temp;
	  }
	  iter = iter->next;
	  count++;
	}
      }
     return;
    }

void Hand::add(Card* c) {
      if (!first && !last) { // Empty list
        first = c;
	last = c;
      }
      else { // Append to end of list
      last->next = c;
      last = c;
      }
    }

Hand::~Hand() { // Destructor
      if (first == last) delete first;
      else {
      Card* iter = first;
      Card* temp;
      while (iter) {
        temp = iter->next;
	delete iter;
	iter = temp;
      }
      }
    }

