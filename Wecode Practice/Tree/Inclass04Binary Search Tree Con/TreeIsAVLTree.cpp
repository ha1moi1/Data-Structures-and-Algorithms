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
    if(!p) return nullptr;
    p->data = x;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void insertEle(Tree &t, int x)
{
    if(!t)
    {
        t = CreateNode(x);
        return;
    }

    if(x == t->data) return;

    if(x < t->data) insertEle(t->left, x);
    else insertEle(t->right, x);
}

void inputTree(Tree &t)
{
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        insertEle(t, x);
    }
}

int treeHeight(Tree t)
{
    if (!t) return 0;

    int leftHeight = treeHeight(t->left);
    int rightHeight = treeHeight(t->right);

    return 1 + max(leftHeight, rightHeight);
}


bool isAVL(Tree t)
{
    if (!t) return true;

    int leftHeight = treeHeight(t->left);
    int rightHeight = treeHeight(t->right);
    if (abs(leftHeight - rightHeight) > 1) return false;
    return isAVL(t->left) && isAVL(t->right);
}


int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<isAVL(T);
	return 0;
}
