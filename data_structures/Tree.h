#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* parent;
    Node* leftChild;
    Node* rightChild;
};

class Tree{
    Node* ROOT;
    void searchRecursive(Node*, int);
public:
    Tree();
    void insert(int);
    void search(int);
    void traverseAndPrint();
    void deleteNode();
    ~Tree();
};