
#include <iostream>
#include "cards.h"
using namespace std;

CardsBST::CardsBST() : root(nullptr) {}

CardsBST::~CardsBST()
{
    clear(root);
}

void CardsBST::insert(Cards c)
{
    if (!root)
    {
        root = new cardNode(c);
        return;
    }
    else
    {
        return insert(c, root);
    }
}

void CardsBST::insert(Cards c, cardNode *p)
{
    if (p->card == c)
        return;
    else if (c > p->card)
    {
        if (p->right)
            insert(c, p->right);
        else
        {
            p->right = new cardNode(c);
            p->right->parent = p;
            return;
        }
    }
    else
    {
        if (p->left)
            insert(c, p->left);
        else
        {
            p->left = new cardNode(c);
            p->left->parent = p;
            return;
        }
    }
}

void CardsBST::remove(Cards c)
{
    // cout << "Time to Remove!" << endl;
    cardNode *p = findNode(c, this->root);
    // cout << "Removing...";
    // p->card.printCard();

    /*if (p->parent)
    {
        cout << "Parent Card: ";
        p->parent->card.printCard();
    }*/
    // cout << "Node Removed Found" << endl;
    if (!p)
    {
        // cout << "removed Node not Found!!" << endl;
        return;
    }

    cardNode *parent = p->parent;
    // cout << "Parent unaccessible" << endl;

    if (!p->left && !p->right)
    {
        // cout << "NODE HAS NO CHILDREN" << endl;
        //  cout << "case1" << endl;
        if (p != root)
        {
            if (parent->right == p)
            {
                // cout << "right child parent: ";
                // parent->card.printCard();
                parent->right = nullptr;
                p = nullptr;
            }
            else
            {
                // cout << "left child parent: ";
                // parent->card.printCard();
                parent->left = nullptr;
                p = nullptr;
            }
        }
        else
        {
            root = nullptr;
        }
        delete p;
    }

    else if (p->left && p->right)
    {
        // cout << "NODE HAS TWO CHILDREN" << endl;
        //  cout << "case1" << endl;
        cardNode *replace = p->right;
        // cout << " " << endl;
        parent = nullptr;

        while (replace->left)
        {
            // cout << "b" << endl;
            parent = replace;
            replace = replace->left;
        }

        if (parent)
        {
            parent->left = replace->right;
        }
        else
        {
            p->right = replace->right;
        }

        p->card = replace->card;

        replace = nullptr;
        free(replace);
    }

    else
    {
        // cout << "ONE CHILD OR NO CHILD" << endl;
        //  cout << "case1" << endl;
        cardNode *replace;

        if (!p->left)
        {
            // cout << "no left child" << endl;
            replace = p->right;
            // replace->card.printCard();
        }
        else
            replace = p->left;

        if (root == p)
        {
            // cout << "root detected" << endl;
            root = replace;
            root->parent = nullptr;
        }
        else
        {
            if (p == parent->left)
            {
                parent->left = replace;
            }
            else
                parent->right = replace;
        }

        p = nullptr;
        delete p;
    }
    return;
}

bool CardsBST::contains(Cards c)
{
    if (this->findNode(c, this->root) == nullptr)
        return false;
    else
        return true;
}

void CardsBST::printInOrder()
{
    printInOrder(this->root);
}

void CardsBST::printInOrder(cardNode *root)
{
    if (root)
    {
        printInOrder(root->left);
        cout << root->card.getSuit() << " " << root->card.getVal() << endl;
        printInOrder(root->right);
    }
}

CardsBST::cardNode *CardsBST::getSuccessorNode(Cards c)
{
    // find node. check if it has a ->left. if not, find the last ->right.

    cardNode *p = this->findNode(c, this->root);
    // cout << "Finding Node Passed" << endl;
    // p->card.printCard();

    /*
        if (p->right)
            cout << "BALLS" << endl;
        if (p->left)
            cout << "BALLS3" << endl;
        if (p->parent)
        {
            cout << "BALLS 7" << endl;
            cout << "Parent card = ";
            p->parent->card.printCard();
        }
        */
    // cout << "Card Find " << p->card.getSuit() << " " << p->card.getVal() << endl;

    if (!p)
    {
        // cout << "Node not found" << endl;
        return nullptr;
    }

    else
    {
        // cout << "Else" << endl;
        if (!p->parent && !p->right)
        {
            // cout << "case 1" << endl;
            return nullptr;
        }

        if (!p->right && p->parent->right == p && p->card > root->card && p->card == this->findMax())
        {
            // cout << "case 2" << endl;
            return nullptr;
        }

        if (p->right)
        {
            // cout << "case 3" << endl;
            p = p->right;
            while (p->left)
            {
                p = p->left;
            }
            return p;
        }
        else if (p->parent->left == p)
        {
            // cout << "case 4" << endl;
            return p->parent;
        }
        else
        {
            // cout << "case 5" << endl;
            cardNode *n = p->parent;
            while (p->card > n->card)
            {
                n = n->parent;
            }
            return n;
        }
    }
}

Cards CardsBST::getSuccessor(Cards c)
{
    // cout << "getSuccessor progress" << endl;
    cardNode *p = getSuccessorNode(c);
    // cout << "getSuccessorNode Passed" << endl;
    Cards x;
    if (!p)
    {
        // cerr << "No Successor Found!" << endl;
        return x;
    }
    else
        return p->card;
}

CardsBST::cardNode *CardsBST::getPredecessorNode(Cards c)
{
    cardNode *p = this->findNode(c, this->root);
    if (!p)
    {
        // cout << "Node Not Found!!" << endl;
        return nullptr;
    }

    else
    {
        // cout << "else" << endl;
        if (!p->parent && !p->left)
        {
            // cout << "case 1" << endl;
            return nullptr;
        }
        if (!p->left && p->parent->left == p && p->card < root->card && p->card == this->findMin())
        {
            // cout << "case 2" << endl;
            return nullptr;
        }

        if (p->left)
        {
            p = p->left;
            while (p->right)
            {
                p = p->right;
            }
            return p;
        }
        // right child
        else if (p->parent->right == p)
        {
            return p->parent;
        }
        // left child
        else
        {
            cardNode *n = p->parent;
            while (p->card < n->card)
            {
                n = n->parent;
            }
            return n;
        }
    }
}

Cards CardsBST::getPredecessor(Cards c)
{
    cardNode *p = this->getPredecessorNode(c);
    Cards x;
    if (!p)
    {
        // cerr << "No Predecessor Found!" << endl;
        return x;
    }
    else
        return p->card;
}

// private functions
CardsBST::cardNode *CardsBST::findNode(Cards c, cardNode *p)
{
    // cout << "finding Node... ";
    // c.printCard();
    //  cout << endl;
    cardNode *n = this->root;
    while (n)
    {
        // cout << "balls2" << endl; // LINE SEG FAULT
        // n->card.printCard();
        // cout << "While loop" << endl;
        if (c == n->card)
        {
            // cout << "card equaled!" << endl;
            return n;
        }
        else if (c > n->card)
        {
            // cout << "card greater than" << endl;

            n = n->right;
        }
        else if (c < n->card)
        {
            // cout << "card less than " << endl;

            n = n->left;
            // cout << "balls" << endl;
        }
    }
    // cout << "Returning null...." << endl;
    return nullptr;
}

void CardsBST::clear(cardNode *root)
{
    if (root)
    {
        clear(root->left);
        clear(root->right);
        delete root;
    }
}

CardsBST::cardNode *CardsBST::minNode()
{
    cardNode *p = this->root;
    while (p && p->left)
    {
        p = p->left;
    }
    return p;
}

Cards CardsBST::findMin()
{
    cardNode *p = minNode();
    return p->card;
}

CardsBST::cardNode *CardsBST::maxNode()
{
    cardNode *p = this->root;
    while (p && p->right)
    {
        p = p->right;
    }
    return p;
}
Cards CardsBST::findMax()
{
    cardNode *p = maxNode();
    return p->card;
}