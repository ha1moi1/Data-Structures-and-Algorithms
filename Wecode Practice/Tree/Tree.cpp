#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

typedef Node* Tree;

void initTree(Tree &T)
{
    T = nullptr;
}

Node* createNode(int x)
{
    Node* p = new Node;
    p->data = x;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}


int main()
{
    Tree T = nullptr;
    inputTree(T);
    cout << "NLR: ";
    NLR(T);
    return 0;
}
