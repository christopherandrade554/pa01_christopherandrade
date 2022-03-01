//Christopher Andrade Perm: 5698618
// 2/28/2022
#include <iostream>

#include <string>

#include "utility.h"

using namespace std;

Select::Select(): suit(0), value(0) {}
Select::~Select() {}

Select::Select(int s, int v) {
  suit = s;
  value = v;
}


int Select::getSuit() const {
  return suit;
}

int Select::getVal() const {
  return value;
}


void Select::setSelect(int suit, int value) {
  this -> suit = suit;
  this -> value = value;
}

bool operator < (Select
  const & c1, Select
  const & c2) {
  
  int suit1 = c1.suit;
  int suit2 = c2.suit;
  int val1 = c1.value;
  int val2 = c2.value;

  if (c1.suit == c2.suit && c1.value == c2.value)
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
  int val1 = c1.value;
  int val2 = c2.value;


  if (c1.suit == c2.suit && c1.value == c2.value)
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
  if (c1.suit == c2.suit && c1.value == c2.value){
 return true;
  }else{
return false;
  }
    
}

void Select::printSelect() const {
  string printV, printS;


   if (this -> value == 1) {
    printV = "a";
  } else if (this -> value == 11) {
    printV = "j";
  } else if (this -> value == 12) {
    printV = "q";
  } else{
    printV = "k";
  } 
  if (this -> suit == 1) {
    printS = "c";
  } else if (this -> suit == 2) {
    printS = "d";
  } else if (this -> suit == 3) {
    printS = "s";
  } else {
    printS = "h";
  }

 
  cout << printS << " " << printV << endl;
}