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

void LNR(Tree t) 
{
    if (!t) return;
    LNR(t->left);
    cout << t->data << " ";
    LNR(t->right);
}

Node* Search(Tree t, int x)
{
    if (t != NULL)
    {
        if (t->data == x) return t;
        if (t->data > x) return Search(t->left, x);
        return Search(t->right, x);
    }
    return NULL;
}

int minValue(Tree t)
{
    if (!t)
        return -1;

    while (t->left)
        t = t->left;
    return t->data;
}


int maxValue(Tree t)
{
    if (!t)
        return -1;

    while (t->right)
        t = t->right;
    return t->data;
}
 
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T); cout<<endl;


    int x; cout<<"\nEnter the element you want to find: ";cin>>x;
    Node *p=Search(T,x);
    if (p) cout<< "Found";
    else cout<<"Not found";
    cout<<"\nMinimum value in BTS is "<<minValue(T);
    cout<<"\nMinimax value in BTS is "<<maxValue(T);


	return 0;
}