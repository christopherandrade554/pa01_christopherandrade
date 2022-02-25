
// Christopher Andrade Perm:5698618
//Date 2/24/222
#ifndef CARDS_H
#define CARDS_H
#include <iostream>
#include "utility.h"
using namespace std;

class Deck
{
public:
    Deck();
    ~Deck();
    void printInOrder();
    cardsInDeck getSuccessor(cardsInDeck c);
    cardsInDeck getPredecessor(cardsInDeck c);
    cardsInDeck Min();
    cardsInDeck Max();
    void insert(cardsInDeck c);
    void remove(cardsInDeck c);
    bool contains(cardsInDeck c);



private:
    struct Node
    {
        Node *left, *right, *parent;
        cardsInDeck card;
        Node(cardsInDeck c1)
        {
            card = c1;
            //left = right = parent = nullptr;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }
    };

    Node *root;

    Node *locate(cardsInDeck c, Node *p);
    Node *getSuccessorNode(cardsInDeck c);
    Node *getPredecessorNode(cardsInDeck c);
    Node *smNode();
    Node *bgNode();
    void printInOrder(Node *root);
    void insert(cardsInDeck c, Node *p);
    void clear(Node *root);
};

#endif