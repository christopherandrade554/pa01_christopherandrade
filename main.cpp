//Christopher Andrade
#include <iostream>

#include <fstream>

#include <string>

#include <cstring>

#include "utility.h"

#include "cards.h"

using namespace std;

int main(int argv, char ** argc) {
  if (argv < 3) {
    cout << "Please provide 2 file names" << endl;
    return 1;
  }

  ifstream cardFile1(argc[1]);
  ifstream cardFile2(argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail()) {
    cout << "Could not open file " << argc[2];
    return 1;
  }

  Deck BST1;
  Deck BST2;
  // Read each file
  while (getline(cardFile1, line) && (line.length() > 0)) {
    string suitcp = line.substr(0, 1);
    char suit[1];
    strcpy(suit, suitcp.c_str());
    string val = line.substr(2, 2);
    Selected card;
    card. setC(suit[0], val);
    BST1.insert(card);
  }

  cardFile1.close();

  while (getline(cardFile2, line) && (line.length() > 0)) {
    string suitcp = line.substr(0, 1);
    char suit[1];
    strcpy(suit, suitcp.c_str());
    string val = line.substr(2, 2);
    Selected card;
    card. setC(suit[0], val);
    BST2.insert(card);
  }
  cardFile2.close();

  Selected nullCard('z', "0");

  Selected a = BST1.Min();
  Selected b = BST2.Max();

  Selected aMax = BST1.Max();
  Selected bMin = BST2.Min();

  while (!(a == nullCard) && !(b == nullCard)) {

    if (BST2.contains(a)) {
      BST2.remove(a);
      cout << "Alice picked matching card " << a.getSuit() << " " << a.getVal() << endl;
      Selected newA = BST1.Successor(a);
      BST1.remove(a);
      a = newA;
    } else if (!BST2.contains(a)) {
      while (!(a == nullCard)) {
        Selected newA = BST1.Successor(a);
        a = newA;
        if (BST2.contains(a)) {
          BST2.remove(a);
          cout << "Alice picked matching card " << a.getSuit() << " " << a.getVal() << endl;
          Selected newA = BST1.Successor(a);
          BST1.remove(a);
          a = newA;
          break;
        }
      }
    }

    if (BST1.contains(b)) {
      BST1.remove(b);
      cout << "Bob picked matching card " << b.getSuit() << " " << b.getVal() << endl;
      Selected newB = BST2.Predecessor(b);
      BST2.remove(b);
      b = newB;
    } else if (!BST1.contains(b)) {
      while (!(b == nullCard)) {
        Selected newB = BST2.Predecessor(b);
        b = newB;
        if (BST1.contains(b)) {
          BST1.remove(b);
          cout << "Bob picked matching card " << b.getSuit() << " " << b.getVal() << endl;
          Selected newB = BST2.Predecessor(b);
          BST2.remove(b);
          b = newB;
          break;
        }
      }
    }
  }
  cout << endl <<
    "Alice's Selected: " << endl;
  BST1.Print();
  cout << endl <<
    "Bob's Selected: " << endl;
  BST2.Print();
  return 0;
}