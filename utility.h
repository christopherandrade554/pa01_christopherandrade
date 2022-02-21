#include <string>
#include <iostream>
using namespace std;

class tree{
    public:
    bool insert(int value); 
    find(int value, Node* n);
    successor(int value);
    predecessor(int value);

    private:
    struct Node {
	int info;
	Node *left, *right, * parent;
	// useful constructor:
    Node(int v=0) : info(v), left(0), right(0), parent(0) { }
    };

    Node *root;

}
