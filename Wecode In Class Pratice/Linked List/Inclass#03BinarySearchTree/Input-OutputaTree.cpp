#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

node *p; //La con tro tro toi node goc, xem nhu la no quan ly cai cay nay va dia dien cho cai cay.
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
    if(t == NULL)
    {
        t = createNode(x);
    }

    if(x == t->data) return;
    if(x < t->data)
        insertNode(t->left, x);
    else 
        insertNode(t->right, x);
}

void inputTree(Tree &t)
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        insertNode(t, x);
    }
}

void NLR(Tree t) // Tiền tự
{
    if(!t) return;
    cout << t->data << " ";
    NLR(t->left);
    NLR(t->right);
}

void LRN(Tree t) // Hậu tự
{
    if(!t) return;
    LRN(t->left);
    LRN(t->right);
    cout << t->data << " ";
}

void LNR(Tree t) // Trung tự
{
    if(!t) return;
    LNR(t->left);
    cout << t->data << " ";
    LNR(t->right);
}


int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	return 0;
}
