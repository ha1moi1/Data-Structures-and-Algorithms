#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

typedef node* Tree;

node* CreateNode(int x)
{
    node* p = new node;
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

void NLR(Tree t)
{
    if (!t) return;
    cout << t->data << " ";
    NLR(t->left);
    NLR(t->right);
}

void LRN(Tree t) 
{
    if (!t) return;
    LRN(t->left);
    LRN(t->right);
    cout << t->data << " ";
}

void LNR(Tree t) 
{
    if (!t) return;
    LNR(t->left);
    cout << t->data << " ";
    LNR(t->right);
}

void listLeafs(Tree t)
{
    if (!t) return; 

    if (!t->left && !t->right)
    {
        cout << t->data << " ";
    }

    listLeafs(t->left);
    listLeafs(t->right);
}

void listNodesWithOneChild(Tree t)
{
    if (!t) return;

    if ((t->left && !t->right) || (!t->left && t->right))
    {
        cout << t->data << " ";
    }

    listNodesWithOneChild(t->left);
    listNodesWithOneChild(t->right);
}

void listNodesWithTwoChildren(Tree t)
{
    if (!t) return;

    if (t->left && t->right)
    {
        cout << t->data << " ";
    }
    listNodesWithTwoChildren(t->left);
    listNodesWithTwoChildren(t->right);
}


void listInternalNodes(Tree t, int i)
{
    if(i != 0)
    {
        if (!t)
        return;

        if (t->left || t->right)
        cout << t->data << " ";
    }
    i++;
    listInternalNodes(t->left, i);
    listInternalNodes(t->right, i);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	cout<<"\nLeaf nodes: "; listLeafs(T);
	cout<<"\nInternal nodes: "; listInternalNodes(T,0); //co de san tham so thu 2 cho ai co nhu cau dung, SV khong dung tham so thu 2 nay cung khong sao
	cout<<"\nNodes with one child: "; listNodesWithOneChild(T);
	cout<<"\nNodes with two children: "; listNodesWithTwoChildren(T);

	return 0;
}