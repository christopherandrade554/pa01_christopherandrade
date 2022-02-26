#include <iostream>
#include "cards.h"
#include "utility.h"
using namespace std;

int main()
{

    /*  alice Selected
    c j
    s 10
        bob Selected
    c 9
    d 2
    */

    Deck Alice, Bob;
    Selected cJ('c', "j");
    Selected s10('s', "10");
    Selected c6('c', "6");
    Selected c9('c', "9");
    Selected d2('d', "2");
    Selected hK('h', "k");

    Selected nullCard('z', "0");

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
    Alice.Print();
    cout << "Bob's Hand: " << endl;
    Bob.Print();

    cout << "Successors / Predecessors Test" << endl;
    Selected p = Alice.Predecessor(cJ);
    cout << "Predecessor: " << p.getSuit() << " " << p.getVal() << endl;
    cout << "Predecessor: " << Bob.Predecessor(d2).getSuit() << " " << Bob.Predecessor(d2).getVal() << endl;
    cout << "Successor: " << Alice.Successor(c6).getSuit() << " " << Alice.Successor(c6).getVal() << endl;
    cout << "Successor: " << Bob.Successor(c9).getSuit() << " " << Bob.Successor(c9).getVal() << endl;

    cout << "Max / Min Test" << endl;
    cout << "Alice's Max: " << Alice.Max().getSuit() << " " << Alice.Max().getVal() << endl;
    cout << "Alice's Min: " << Alice.Min().getSuit() << " " << Alice.Min().getVal() << endl;
    cout << "Bob's Max: " << Bob.Max().getSuit() << " " << Bob.Max().getVal() << endl;
    cout << "Bob's Min: " << Bob.Min().getSuit() << " " << Bob.Min().getVal() << endl;

    Selected aMax = Alice.Min();
    Selected bMin = Bob.Max();

    while (!(aMax == nullCard) & !(bMin == nullCard))
    {
        cout << " ALICE Selected " << endl;
        Alice.Print();
        cout << " BOB Selected " << endl;
        Bob.Print();
        if (Bob.contains(aMax))
        {
            cout << "bob contains alice." << endl;
            Bob.remove(aMax);
            // cout << "successfully removed in BOB" << endl;
        }
        Selected a = Alice.Successor(aMax);
        // cout << "successor got ";
        Alice.remove(aMax);
        aMax = a;
    }
    cout << "Alice's Selected: \n";
    Alice.Print();
    cout << "Bob's Selected: \n";
    Bob.Print();

    return 0;
}

