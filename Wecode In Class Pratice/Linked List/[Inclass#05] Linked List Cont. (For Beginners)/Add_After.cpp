#include <iostream>
using namespace std;

struct node
{
    int data;
    node* link;
};

struct List
{
    node* head;
    node* tail;
};

void CreateList(List &l)
{
    l.head = NULL;
    l.tail = NULL;
}

node* CreateNode(int data)
{
    node* p = new node;
    if(p == NULL) return NULL;
    p->data = data;
    p->link = NULL;
    return p;
}

void addHead(List &l, node* p)
{
    if(l.head == NULL)
    {
        l.head = p;
        l.tail = l.head;
    }
    else
    {
        p->link = l.head;
        l.head = p;
    }
}

void addTail(List &l, node* p)
{
    if(l.head == NULL)
    {   
        l.head = p;
        l.tail = l.head;
    }
    else 
    {
        l.tail->link = p;
        l.tail = p;
    }
}

void insertAfterQ(List &l, node* p, node* q)
{
    if(q != NULL)
    {
        p->link = q->link;
        q->link = p;
        if(l.tail == q) l.tail = p;
    }
    else 
    {
        addHead(l, p);
    }
}

void printList(List l)
{
    node* p;
    p = l.head;

    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->link;
    }
}

node* search(List l, int x)
{
    node* p;
    p = l.head;
    while((p != NULL))
    {
        if(p->data == x)
        {
            return p;
        }
        p = p->link;
    }
    return NULL;
}

int main()
{
    List l;
    CreateList(l);
    int temp;
    while(1)
    {
        cin >> temp;
        if(temp == 3) break;
        int n;
        cin >> n;
        
        if(temp == 0)
        {
            node *p = CreateNode(n);
            addHead(l, p);
        }
        else if(temp == 1)
        {
            node *p = CreateNode(n);
            addTail(l, p);
        }
        else if(temp == 2)
        {
            int m;
            cin >> m;
            node* p = CreateNode(m);
            node *q = search(l, n);
            if(q == NULL)
            {
                addHead(l, p);
            }
            else insertAfterQ(l, p, q);
        }
    }

    printList(l);
}