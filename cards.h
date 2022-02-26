#ifndef CARDS_H
#define CARDS_H

#endif
#include <iostream>
using namespace std;

class Card {
  public:
    char suit;
    char value;
    Card *next;
    
    // Constructor
    Card(char x, char y);
    
    // Equality Overload
    bool operator == (const Card& c);
    
    // Output Overload
    friend ostream& operator<<(ostream& os, Card& c) {
      os << c.suit << " " << c.value;
      return os;
    }


};

class Hand {
  public:
    Card* first;
    Card* last;
    Hand(); // Constructor
    int contains(Card* c);

    void remove(int x);
 
    void add(Card* c);
  
    ~Hand(); // Destructor
};
