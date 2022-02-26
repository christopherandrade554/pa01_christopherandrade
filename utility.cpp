//Christopher Andrade
#include <iostream>

#include <map>

#include "utility.h"

using namespace std;

Selected::~Selected() {}
Selected::Selected(): suit('z'), value("0") {}


Selected::Selected(char s, string v) {
  suit = s;
  value = v;
}

void Selected::setC(char & suit, string & value) {
 this -> value = value;
  this -> suit = suit;
 
}
char Selected::getSuit() const {
  return suit;
}

string Selected::getVal() const {
  return value;
}

bool operator < (Selected
  const & c1, Selected
  const & c2) {

  if (c1.suit == c2.suit && c1.value == c2.value)
    return false;

  int suit1;
  switch (c1.suit) {
  case 'c':
    suit1 = 1;
    break;

  case 'd':
    suit1 = 2;
    break;

  case 's':
    suit1 = 3;
    break;

  case 'h':
    suit1 = 4;
    break;
  }

  int suit2;
  switch (c2.suit) {
  case 'c':
    suit2 = 1;
    break;

  case 'd':
    suit2 = 2;
    break;

  case 's':
    suit2 = 3;
    break;

  case 'h':
    suit2 = 4;
    break;
  }

  map < string, int > cardFace;
  cardFace["a"] = 1;
  cardFace["2"] = 2;
  cardFace["3"] = 3;
  cardFace["4"] = 4;
  cardFace["5"] = 5;
  cardFace["6"] = 6;
  cardFace["7"] = 7;
  cardFace["8"] = 8;
  cardFace["9"] = 9;
  cardFace["10"] = 10;
  cardFace["j"] = 11;
  cardFace["q"] = 12;
  cardFace["k"] = 13;

  auto val1 = cardFace.find(c1.value);
  auto val2 = cardFace.find(c2.value);

  if (suit1 < suit2) {
    return true;
  } else if (suit1 > suit2) {
    return false;
  } else {
    if (val1 -> second < val2 -> second) {
      return true;
    } else
      return false;
  }
}

bool operator > (Selected
  const & c1, Selected
  const & c2) {
  if (c1.suit == c2.suit && c1.value == c2.value)
    return false;
  if (c1 < c2)
    return false;
  else
    return true;
}

bool operator == (Selected
  const & c1, Selected
  const & c2) {
  if (c1.suit == c2.suit && c1.value == c2.value)
    return true;
  else
    return false;
}

void Selected::printCard() const {
  cout << this -> suit << " " << this -> value << endl;
}