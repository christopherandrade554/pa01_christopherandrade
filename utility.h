
// Christopher Andrade Perm:5698618
//Date 2/24/222
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <map>
using namespace std;

class cardsInDeck
{
public:
    cardsInDeck();
    ~cardsInDeck();
    cardsInDeck(char s, string v);
    void setCard(char &suit, string &val);
    char getSuit() const;
    string getValue() const;
    void printCards() const;

    friend bool operator<(cardsInDeck const &c1, cardsInDeck const &c2);
    friend bool operator>(cardsInDeck const &c1, cardsInDeck const &c2);
    friend bool operator==(cardsInDeck const &c1, cardsInDeck const &c2);

private:
    char suit;
    string value;
    map<string, int> cardFace;
};

#endif

