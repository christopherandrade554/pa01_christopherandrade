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

    CardsBST Alice, Bob;
    Cards cJ('c', "j");
    Cards s10('s', "10");
    Cards c6('c', "6");
    Cards c9('c', "9");
    Cards d2('d', "2");
    Cards hK('h', "k");

    Cards nullCard('z', "0");

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
    Cards p = Alice.getPredecessor(cJ);
    cout << "Predecessor: " << p.getSuit() << " " << p.getVal() << endl;
    cout << "Predecessor: " << Bob.getPredecessor(d2).getSuit() << " " << Bob.getPredecessor(d2).getVal() << endl;
    cout << "Successor: " << Alice.getSuccessor(c6).getSuit() << " " << Alice.getSuccessor(c6).getVal() << endl;
    cout << "Successor: " << Bob.getSuccessor(c9).getSuit() << " " << Bob.getSuccessor(c9).getVal() << endl;

    cout << "Max / Min Test" << endl;
    cout << "Alice's Max: " << Alice.findMax().getSuit() << " " << Alice.findMax().getVal() << endl;
    cout << "Alice's Min: " << Alice.findMin().getSuit() << " " << Alice.findMin().getVal() << endl;
    cout << "Bob's Max: " << Bob.findMax().getSuit() << " " << Bob.findMax().getVal() << endl;
    cout << "Bob's Min: " << Bob.findMin().getSuit() << " " << Bob.findMin().getVal() << endl;

    Cards aMax = Alice.findMin();
    Cards bMin = Bob.findMax();

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
            // cout << "successfully removed in BOB" << endl;
        }
        Cards a = Alice.getSuccessor(aMax);
        // cout << "successor got ";
        Alice.remove(aMax);
        aMax = a;
    }
    cout << "Alice's cards: \n";
    Alice.printInOrder();
    cout << "Bob's cards: \n";
    Bob.printInOrder();

    return 0;
}

