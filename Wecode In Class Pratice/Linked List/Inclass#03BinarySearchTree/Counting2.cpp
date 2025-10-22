#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

typedef node* Tree;

node* createNode(int x)
{
    node* p = new node;
    if(p == NULL) return NULL;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(Tree &t, int x)
{
    if(!t)
    {
        t = createNode(x);
    }
    if(t->data == x) return;
    if(x < t->data)
        insertNode(t->left, x);
    else 
        insertNode(t->right, x);
}

void inputTree(Tree &t)
{
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        insertNode(t, x);
    }
}

void LNR(Tree t) 
{
    if(!t) return;
    LNR(t->left);
    cout << t->data << " ";
    LNR(t->right);
}

int countNodes(Tree t)
{
    if(!t) return 0;
    return 1 + countNodes(t->left) + countNodes(t->right);
}

int depthOfTree(Tree t)
{
    if (t == NULL) return -1;
    int leftDepth = depthOfTree(t->left);
    int rightDepth = depthOfTree(t->right);
    return 1 + max(leftDepth, rightDepth);
}

void countEven(Tree A, int &count)
{
    if (A == NULL) return;
    if (A->data % 2 == 0) count++;
    countEven(A->left, count);
    countEven(A->right, count);
}

void countOdd(Tree A, int &count)
{
    if (A == NULL) return;
    if (A->data % 2 != 0) count++;
    countOdd(A->left, count);
    countOdd(A->right, count);
}

int countPositive(Tree A)
{
    if (A == NULL) return 0;
    return (A->data > 0) + countPositive(A->left) + countPositive(A->right);
}

int countNegative(Tree A)
{
    if (A == NULL) return 0;
    return (A->data < 0) + countNegative(A->left) + countNegative(A->right);
}

bool isPrime(int n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int countPrime(Tree T)
{
    if (T == NULL) return 0;
    return (isPrime(T->data) ? 1 : 0)
           + countPrime(T->left) + countPrime(T->right);
}

void listPrime(Tree T)   // NLR
{
    if (T == NULL) return;
    if (isPrime(T->data))
        cout << T->data << " ";
    listPrime(T->left);
    listPrime(T->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);



	return 0;
}