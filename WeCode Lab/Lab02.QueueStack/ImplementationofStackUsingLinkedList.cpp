
#include <iostream>
using namespace std;

/*Cach 1: Khi da cai dat List roi, dinh nghia Stack dua tren List
struct Stack
{
	List L;
};

Cach 2: Cai dat lai Stack tu dau, giong nhu List
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead; // pTail khong co cung duoc

};*/

struct node
{
    int data;
    node* next;
};

struct List
{
    node* head;
    node* tail;
};

typedef List Stack;

void Init(List &S)
{
    S.head = nullptr;
    S.tail = nullptr;
}

node* CreateNode(int x)
{
    node* p = new node;
    if(!p) return nullptr;
    p->data = x;
    p->next = nullptr;
    return p;
}

void addHead(List &S, node* p)
{
    if(S.head == NULL) 
    {
        S.head = p;
        S.tail = S.head;
    }
    else 
    {
        p->next = S.head;
        S.head = p;
    } 
}

void DecimaltoBinary1(int n, List &S)
{
    while(n != 0)
    {
        int c = (n % 2);
        node* p = CreateNode(c);
        addHead(S, p);
        n /= 2;
    }
}

void printStack(List S)
{
    if(S.head == nullptr)
    {
        cout << 0;
        return;
    } 
    node* p = S.head;
    while(p)
    {
        cout << p->data;
        p = p->next;
    }
}

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary1(n,S);
    printStack(S);
    return 0;
}

