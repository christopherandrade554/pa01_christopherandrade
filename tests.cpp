#include <iostream>
#include "cards.h"
#include "utility.h"
using namespace std;

int main()
{

    /*  alice cards
    c j
    s 10
        bob cards
    c 9
    d 2
    */

    Deck Alice, Bob;
    cardsInDeck cJ('c', "j");
    cardsInDeck s10('s', "10");
    cardsInDeck c6('c', "6");
    cardsInDeck c9('c', "9");
    cardsInDeck d2('d', "2");
    cardsInDeck hK('h', "k");

    cardsInDeck nullCard('z', "0");

    Alice.insert(cJ);
    Alice.insert(s10);
    Alice.insert(c6);
    Alice.insert(hK);
    Bob.insert(c9);
    Bob.insert(d2);
    Bob.insert(hK);
    Bob.insert(c6);

    cout << "Testing In Order" << endl;
    cout << "Alice's Hand: " << endl;
    Alice.printInOrder();
    cout << "Bob's Hand: " << endl;
    Bob.printInOrder();

    cout << "Successors / Predecessors Test" << endl;
    cardsInDeck p = Alice.getPredecessor(cJ);
    cout << "Predecessor: " << p.getSuit() << " " << p.getValue() << endl;
    cout << "Predecessor: " << Bob.getPredecessor(d2).getSuit() << " " << Bob.getPredecessor(d2).getValue() << endl;
    cout << "Successor: " << Alice.getSuccessor(c6).getSuit() << " " << Alice.getSuccessor(c6).getValue() << endl;
    cout << "Successor: " << Bob.getSuccessor(c9).getSuit() << " " << Bob.getSuccessor(c9).getValue() << endl;

    cout << "Max / Min Test" << endl;
    cout << "Alice's Max: " << Alice.Max().getSuit() << " " << Alice.Max().getValue() << endl;
    cout << "Alice's Min: " << Alice.Min().getSuit() << " " << Alice.Min().getValue() << endl;
    cout << "Bob's Max: " << Bob.Max().getSuit() << " " << Bob.Max().getValue() << endl;
    cout << "Bob's Min: " << Bob.Min().getSuit() << " " << Bob.Min().getValue() << endl;

    cardsInDeck aMax = Alice.Min();
    cardsInDeck bMin = Bob.Max();

    while (!(aMax == nullCard) & !(bMin == nullCard))
    {
        cout << " ALICE CARDS " << endl;
        Alice.printInOrder();
        cout << " BOB CARDS " << endl;
        Bob.printInOrder();
        if (Bob.contains(aMax))
        {
            cout << "bob contains alice." << endl;
            Bob.remove(aMax);
        }
        cardsInDeck a = Alice.getSuccessor(aMax);
        Alice.remove(aMax);
        aMax = a;
    }
    cout << "Alice's cards: \n";
    Alice.printInOrder();
    cout << "Bob's cards: \n";
    Bob.printInOrder();

    return 0;
}