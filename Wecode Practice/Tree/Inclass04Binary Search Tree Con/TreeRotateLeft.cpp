#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

typedef Node* Tree;

Node* CreateNode(int x)
{
    Node* p = new Node;
    if (!p) return nullptr;
    p->data = x;
    p->left = p->right = nullptr;
    return p;
}

void insertEle(Tree &t, int x)
{
    if (!t)
    {
        t = CreateNode(x);
        return;
    }
    if (x == t->data) return;
    if (x < t->data) insertEle(t->left, x);
    else insertEle(t->right, x);
}
void inputTree(Tree &t)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertEle(t, x);
    }
}
void NLR(Tree t)
{
    if (!t) return;
    cout << t->data << " ";
    NLR(t->left);
    NLR(t->right);
}
void rotateLeft(Tree &t)
{
    if (!t)
    {
        cout << "\nKhong the xoay vi cay rong";
        return;
    }

    if (!t->right)
    {
        cout << "\nKhong the xoay trai vi khong co nut con ben phai";
        return;
    }
    Tree newRoot = t->right;
    t->right = newRoot->left;
    newRoot->left = t;
    t = newRoot; 
}

int main()
{
    Tree T = NULL;
    inputTree(T);

    cout << "NLR: ";
    NLR(T);

    rotateLeft(T);
    if (T) 
    {
        cout << "\nNLR: ";
        NLR(T);
    }
    return 0;
}
