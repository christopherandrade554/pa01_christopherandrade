//Christopher Andrade
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

using namespace std;

class Select {
  public:
    Select();
  ~Select();
  Select(int s, int v);
  void setSelect(int suit, int val);
  int getSuit() const;
  int getVal() const;
  void printSelect() const;

  friend bool operator < (Select
    const & c1, Select
    const & c2);
  friend bool operator > (Select
    const & c1, Select
    const & c2);
  friend bool operator == (Select
    const & c1, Select
    const & c2);

  private:
    int suit;
  int val;
};

#endif