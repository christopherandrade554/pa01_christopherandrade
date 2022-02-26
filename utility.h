//Christopher Andrade
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

#include <map>

using namespace std;

class Cards {
  public:
    Cards();
  ~Cards();
  Cards(char s, string v);

    
  friend bool operator < (Cards
    const & c1, Cards
    const & c2);
  friend bool operator > (Cards
    const & c1, Cards
    const & c2);
  friend bool operator == (Cards
    const & c1, Cards
    const & c2);

  void setCard(char & suit, string & val);
  char getSuit() const;
  string getVal() const;
  void printCard() const;

  private:
    char suit;
  string val;
  map < string, int > cardFace;
};

#endif