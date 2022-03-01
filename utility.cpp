//Christopher Andrade Perm: 5698618
// 2/28/2022
#include <iostream>

#include <string>

#include "utility.h"

using namespace std;

Select::Select(): suit(0), val(0) {}
Select::~Select() {}

Select::Select(int s, int v) {
  suit = s;
  val = v;
}


int Select::getSuit() const {
  return suit;
}

int Select::getVal() const {
  return val;
}


void Select::setSelect(int suit, int val) {
  this -> suit = suit;
  this -> val = val;
}

bool operator < (Select
  const & c1, Select
  const & c2) {
  
  int suit1 = c1.suit;
  int suit2 = c2.suit;
  int val1 = c1.val;
  int val2 = c2.val;

  if (c1.suit == c2.suit && c1.val == c2.val)
    return false;

  if (suit1 < suit2) {
    return true;
  } else if (suit1 > suit2) {
    return false;
  } else {
    if (val1 < val2) {
      return true;
    } else
      return false;
  }
}

bool operator > (Select
  const & c1, Select
  const & c2) {
  int suit1 = c1.suit;
  int suit2 = c2.suit;
  int val1 = c1.val;
  int val2 = c2.val;


  if (c1.suit == c2.suit && c1.val == c2.val)
    return false;

  if (suit1 < suit2) {
    return false;
  } else if (suit1 > suit2) {
    return true;
  } else {
    if (val1 < val2) {
      return false;
    } else
      return true;
  }
}

bool operator == (Select
  const & c1, Select
  const & c2) {
  if (c1.suit == c2.suit && c1.val == c2.val){
 return true;
  }
  else{
return false;
  }
    
}

void Select::printSelect() const {
  string printV, printS;


   if (this -> val == 1) {
    printV = "a";
  } else if (this -> val == 11) {
    printV = "j";
  } else if (this -> val == 12) {
    printV = "q";
  } else if (this -> val == 13) {
    printV = "k";
  } else if (this -> val == 0) {
    printV = "NULL";
  } else {
    printV = to_string(this -> val);
  }

  if (this -> suit == 1) {
    printS = "c";
  } else if (this -> suit == 2) {
    printS = "d";
  } else if (this -> suit == 3) {
    printS = "s";
  } else if (this -> suit == 4) {
    printS = "h";
  } else {
    printS = "NULL";
  }

 
  cout << printS << " " << printV << endl;
}