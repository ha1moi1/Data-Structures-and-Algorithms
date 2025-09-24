
#include <iostream>
using namespace std;

struct node
{
    string data;
    node* link;
};

struct List
{
    node* head;
    node* tail;
};

int RemoveHead(List &l)
{
    node* p;
    if(l.head != NULL)
    {
        p = l.head;
        l.head = l.head->link;
        delete p;
        if(l.head == NULL) l.tail = NULL;
        return 1;
    }
    return 0;
}

void CreateList(List &l)
{
    l.head = NULL;
    l.tail = NULL;
}

node* CreateNode(string data)
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

void printList(List l, int stt)
{
    node* p;
    p = l.head;
    if(p == NULL)
    {
        cout << "Tiem qua e, khong co khach nao" << endl;
        return;
    }
    while(p != NULL)
    {
        cout << stt++ << " " << p->data << endl;
        p = p->link;
    }
}

int main()
{
    int index;
    string dish;
    List l;
    int stt = 1;
    CreateList(l);
    while(1)
    {
        cin >> index;
        if(index == -1) break;
        if(index == 0)
        {
            cin >> dish;
            node* p = CreateNode(dish);
            addTail(l, p);
        }
        else if(index == 1)
        {
            stt += RemoveHead(l);
        }
    }

    printList(l, stt);
}