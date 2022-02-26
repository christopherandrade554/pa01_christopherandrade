//Christopher Andrade
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

#include <map>

using namespace std;

class Selected {
public:
    Selected();
    ~Selected();
    Selected(char s, string v);

    friend bool operator==(Selected const& c1, Selected const& c2);
    friend bool operator<(Selected const& c1, Selected const& c2);
    friend bool operator>(Selected const& c1, Selected const& c2);
   
    string getVal() const;
    void printCard() const;
    void setC(char& suit, string& val);
    char getSuit() const;
 

//private:
    string value;
    char suit;
    map<string, int> faceVal;
};

#endif