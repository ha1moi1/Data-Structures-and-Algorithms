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

void printList(List l)
{
    Node* p;
    p = l.pHead;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->link;
    }
}

int main()
{
    List l;
    CreateList(l);
    int temp = 0;
    while(temp != 3)
    {
        cin >> temp;
        if(temp == 3) break;
        int n;
        cin >> n;
        if(temp == 0)
        {
            Node* p = CreateNode(n);
            addHead(p, l);
        }
    }

    printList(l);
}