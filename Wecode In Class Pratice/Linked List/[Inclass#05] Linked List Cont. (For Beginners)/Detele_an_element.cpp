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
    p->data = data;
    p->link = NULL;
    return p;
}

void addHead(List &l, node* p)
{
    if(l.head == NULL)
    {
        l.head = p;
        l.tail = p;
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
        l.tail = p;
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

void RemoveHead(List &l)
{
    node* p;
    if(l.head != NULL)
    {
        p = l.head;
        l.head = l.head->link;
        delete p;
        if(l.head == NULL) l.tail = NULL;
    }
}

void RemoveAfterQ(List &l, node *q, int &x)
{
    node *p;
    if(q != NULL)
    {
        p = q->link;
        
        if(p != NULL)
        {
            if(p == l.tail) l.tail = q;
            q->link = p->link;
            x = p->data;
            delete p;
        }
        return;
    }
}

void RemoveX(List &l, int x)
{
    node* p;
    node *q = NULL;
    p = l.head;

    while((p != NULL) && (p->data != x))
    {
        q = p;
        p = p->link;
    }

    if(p == NULL) return;

    if(q != NULL) RemoveAfterQ(l, q, x);

    else RemoveHead(l);
}

node* findNode(List l, int x)
{
    node* p = l.head;
    while(p != NULL)
    {
        if(p->data == x) return p;
        p = p->link;
    }
    return NULL;
}


void printList(List l)
{
    if(l.head == NULL)
    {
        cout << "blank" << endl;
        return;
    }
    node* p;
    p = l.head;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->link;
    }
}

int main()
{
    int index, data;
    List l;
    CreateList(l);
    while(1)
    {
        cin >> index;
        if(index == 0)
        {
            cin >> data;
            node* p = CreateNode(data);
            addHead(l, p);
        }
        else if(index == 1)
        {
            cin >> data;
            node* p = CreateNode(data);
            addTail(l, p);
        }
        else if(index == 2)
        {
            int a, b;
            cin >> a >> b;
            node* q = findNode(l, a);
            if(q != NULL) insertAfterQ(l, CreateNode(b), q);
            else addHead(l, CreateNode(b));
        }
        else if(index == 3)
        {
            cin >> data;
            RemoveX(l, data);
        }
        else if(index == 5)
        {
            RemoveHead(l);
        }
        else if(index == 6) break;
    }
    printList(l);
}