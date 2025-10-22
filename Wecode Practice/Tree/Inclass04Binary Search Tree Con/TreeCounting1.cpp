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

int countNodes(Tree t)
{
    if(!t) return 0;
    return 1 + countNodes(t->left) + countNodes(t->right);
}

int countLeafs(Tree t)
{
    if (!t) return 0; 

    if (!t->left && !t->right)
        return 1; 

    return countLeafs(t->left) + countLeafs(t->right);
}

int countInternalNodes2(Tree t)
{
    return countNodes(t) - countLeafs(t) - 1;
}

int countInternalNodes(Tree t)
{
    return max(0, countInternalNodes2(t));
}

int countOneChild(Tree t)
{
    if (!t) return 0;

    int count = 0;

    if ((t->left && !t->right) || (!t->left && t->right))
        count = 1;

    return count + countOneChild(t->left) + countOneChild(t->right);
}


int countTwoChildren(Tree t)
{
    if(!t) return 0;
    int count = 0;
    if(t->left && t->right) count++;
    return count + countTwoChildren(t->left) + countTwoChildren(t->right);
}

int countLess(Tree t, int x)
{
    if(!t) return 0;
    int count = 0;
    if(t->data < x) count++;
    return count + countLess(t->left, x) + countLess(t->right, x);
}

int countBetweenValues(Tree t, int x, int y)
{
    if(!t) return 0;
    int count = 0;
    if((t->data > x) && (t->data < y)) count++;
    return count + countBetweenValues(t->left, x, y) + countBetweenValues(t->right, x, y);
}

int main()
{
	// Tree T = NULL;
	// inputTree(T);

    // cout<<"Number of nodes: " << countNodes(T)<<endl;
	// cout<<"Number of leaf nodes: " << countLeafs(T)<<endl;
	// cout<<"Number of internal nodes: "<< countInternalNodes(T)<<endl;
	// cout<<"Number of nodes with one child: "<< countOneChild(T)<<endl;
	// cout<<"Number of nodes with two children: "<< countTwoChildren(T)<<endl;

	// int x;cout<<"Enter x: ";cin>>x;
	// cout<<"\nNumber of nodes less than "<<x<<": "<< countLess(T,x)<<endl;
	// int y; cout<<"Enter x,y: ";cin>>x>>y;
	// cout<<"\nNumber of nodes greater than "<<x<<" and less than "<<y<<": "<< countBetweenValues(T,x,y)<<endl;

    int* x = new int;
    *x = 10;

	return 0;
}