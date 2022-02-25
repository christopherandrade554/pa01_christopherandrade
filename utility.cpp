
// Christopher Andrade Perm:5698618
//Date 2/24/222
#include <iostream>
#include <map>
#include "utility.h"
using namespace std;

cardsInDeck::cardsInDeck() : suit('z'), value("0") {}
cardsInDeck::~cardsInDeck() {}

cardsInDeck::cardsInDeck(char s, string v)
{
    suit = s;
    value = v;
}

void cardsInDeck::setCard(char &suit, string &value)
{
    this->suit = suit;
    this->value = value;
}
char cardsInDeck::getSuit() const
{
    return suit;
}

string cardsInDeck::getValue() const
{
    return value;
}

bool operator<(cardsInDeck const &one, cardsInDeck const &two)
{

    if (one.suit == two.suit && one.value == two.value)
        return false;

    int suit1;
    switch (one.suit)
    {
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
    switch (two.suit)
    {
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

    map<string, int> cardFace;
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

    auto first1 = cardFace.find(one.value);
    auto second2 = cardFace.find(two.value);

    if (suit1 < suit2)
    {
        return true;
    }
    else if (suit1 > suit2)
    {
        return false;
    }
    else // COMPARING THE valueUES
    {
        if (first1->second < second2->second)
        {
            return true;
        }
        else
            return false;
    }
}

bool operator>(cardsInDeck const &one, cardsInDeck const &two)
{
    if (one.suit == two.suit && one.value == two.value)
        return false;
    if (one < two)
        return false;
    else
        return true;
}

bool operator==(cardsInDeck const &one, cardsInDeck const &two)
{
    if (one.suit == two.suit && one.value == two.value){

    
        return true;
    }
    else{


    }
       
}

void cardsInDeck::printCards() const
{
    cout << this->suit << " " << this->value << endl;
}
