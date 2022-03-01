//Christopher Andrade Perm: 5698618
// 2/28/2022
#include <iostream>

#include <fstream>

#include <string>

#include "cards.h"

#include "utility.h"

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

  Deck Deck1;
  Deck Deck2;

  while (getline(cardFile1, line) && (line.length() > 0)) {

    string suit = line.substr(0, 1);
    int valueR;
    if (suit == "c") {
      valueR = 1;
    } else if (suit == "d") {
      valueR = 2;
    } else if (suit == "s") {
      valueR = 3;
    } else {
      valueR = 4;
    }

    int value;
    if (line.length() == 4) {
      value = 10;
    } else if (line.substr(2, 3) == "j") {
      value = 11;
    } else if (line.substr(2, 3) == "q") {
      value = 12;
    } else if (line.substr(2, 3) == "k") {
      value = 13;
    } else if (line.substr(2, 3) == "a") {
      value = 1;
    } else {
      int test1 = stoi(line.substr(2, 3));
      value = test1;
    }
    Select AC;
    AC.setSelect(valueR, value);
    Deck1.insert(AC);
  }
  cardFile1.close();

  while (getline(cardFile2, line) && (line.length() > 0)) {
    string suit = line.substr(0, 1);
    int valueR;

    if (suit == "c") {
      valueR = 1;
    } else if (suit == "d") {
      valueR = 2;
    } else if (suit == "s") {
      valueR = 3;
    } else {
      valueR = 4;
    }

    int value;
    if (line.length() == 4) {
      value = 10;
    } else if (line.substr(2, 3) == "j") {
      value = 11;
    } else if (line.substr(2, 3) == "q") {
      value = 12;
    } else if (line.substr(2, 3) == "k") {
      value = 13;
    } else if (line.substr(2, 3) == "a") {
      value = 1;
    } else {
      int test1 = stoi(line.substr(2, 3));
      value = test1;
    }
    Select BobCard;
    BobCard.setSelect(valueR, value);
    Deck2.insert(BobCard);
  }
  cardFile2.close();

  Select alice = Deck1.getMin();
  Select bob = Deck2.getMax();
  Select blank(0, 0);

  while (!(bob == blank) && !(alice == blank)) {
    if (Deck2.contains(alice)) {
      Deck2.remove(alice);
      cout << "Alice picked matching card ";
      alice.printSelect();
      Select tempA = Deck1.getSuccessor(alice);
      Deck1.remove(alice);
      alice = tempA;
    } else {
      while (!(alice == blank)) {
        Select tempA = Deck1.getSuccessor(alice);

        alice = tempA;
        if (Deck2.contains(alice)) {
          Deck2.remove(alice);
          cout << "Alice picked matching card ";
          alice.printSelect();
          Select tempA = Deck1.getSuccessor(alice);

          Deck1.remove(alice);
          alice = tempA;
          break;
        }
      }
    }

    if (Deck1.contains(bob)) {
      Select tempB = Deck2.getPredecessor(bob);
      Deck1.remove(bob);
      cout << "Bob picked matching card ";
      bob.printSelect();
      Deck2.remove(bob);
      bob = tempB;
    } else {
      while (!(bob == blank)) {
        Select tempB = Deck2.getPredecessor(bob);
        bob = tempB;
        if (Deck1.contains(bob)) {
          Deck1.remove(bob);
          cout << "Bob picked matching card ";
          bob.printSelect();
          Select tempB = Deck2.getPredecessor(bob);
          Deck2.remove(bob);
          bob = tempB;

          break;
        }
      }
    }

  }
  cout << endl << "Alice's cards: " << endl;
  Deck1.sort();
  cout << endl << "Bob's cards: " << endl;
  Deck2.sort();

  return 0;
}