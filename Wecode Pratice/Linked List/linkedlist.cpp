#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

struct List
{
    Node* pHead;
    Node* pTail;
};

void CreateList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

Node* CreateNode(int data)
{
    Node* p = new Node;
    if(p == NULL) exit(1);
    p->data = data;
    p->link = NULL;
    return p;
}

void printList(List l)
{
    Node* p;
    p = l.pHead;
    while(p != NULL)
    {
        cout << p->data << endl;
        p = p->link;
    }
}

void addHead(Node* p, List &l)
{
    if(l.pHead == NULL) 
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else 
    {
        p->link = l.pHead;
        l.pHead = p;
    } 
}

void addTail(Node* p, List &l)
{
    if(l.pHead == NULL) 
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else 
    {
        l.pTail->link = p;
        l.pTail = p;
    } 
}

Node* getNodeAt(List l, int pos)
{
    Node* p = l.pHead;
    int index = 0;
    
    while(p != NULL && index < pos)
    {
        p = p->link;
        index++;
    }
    return p;
}

Node* search(List l, int x)
{
    Node* p;
    p = l.pHead;
    while((p != NULL) && (p->data != x))
    {
        p = p->link;
    }

    return p;
}

int postitionSearch(List l, int x)
{
    Node* p;
    p = l.pHead;
    int count = 0;
    while((p != NULL) && (p->data != x))
    {
        p = p->link;
        count++;
    }

    return count;
}

void insertAfterQ(List &l, Node* p, Node* q)
{
    if(q != NULL)
    {
        p->link = q->link;
        q->link = p;
        if(l.pTail == q) l.pTail = p;
    }
    else addHead(p, l);
}

int main()
{
    List l;
    CreateList(l);
    for(int i = 20; i < 30; i++)
    {
        Node* p = CreateNode(i);
        addTail(p, l);
    }

    Node* p = getNodeAt(l, 4);
    Node* q = new Node;
    q->data = 2;

    insertAfterQ(l, q, p);
    printList(l);
}