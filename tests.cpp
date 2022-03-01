#include "cards.h"
#include "utility.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
 
    Select test1, test2, test3;
     Deck Deck, Deck2;
   
    test1.setSelect(5, 7);
    test2.setSelect(4, 1);
    test3.setSelect(6, 3);
    Deck.insert(test3);
    Deck.insert(test2);
    Deck.insert(test1);
    Deck.sort();


   
    Select containsSelect(5, 2);
    if (Deck.contains(containsSelect)) {
        cout << "Found" << endl;
    }
    else {
        cout << "Error" << endl;
    }


    cout << endl;
    (Deck.getPredecessor(test3)).printSelect();

    cout << endl;
    (Deck.getSuccessor(test3)).printSelect();
 

   cout << endl;
    Deck.remove(test3);
    Deck.sort();



    cout << endl;
    cout << "This is Deck2: " << endl;
    Select card1(3, 1);
    Select card2(1, 1);


    Deck2.insert(card2);
    Deck2.insert(card1);
 
    Deck2.sort();
    cout << "min" << endl;
    (Deck2.getMin()).printSelect();
    cout << "max" << endl;
    (Deck2.getMax()).printSelect();


    cout << "..." << endl;
    Select printTest(3,11);
    printTest.printSelect();
    

}