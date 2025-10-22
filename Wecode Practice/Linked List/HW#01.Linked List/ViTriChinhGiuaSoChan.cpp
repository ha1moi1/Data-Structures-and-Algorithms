#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

struct list
{
    node* head;
    node* tail;
};

void createList(list &l)
{
    l.head = l.tail = nullptr;
}

node* createNode(int x)
{
    node *p = new node;
    if(!p) return nullptr;
    p->data = x;
    p->next = nullptr;
    return p;
}

void addTail(list &l, node* p)
{
    if(l.head == nullptr) //If the List is Empty, add p as the first node in the list
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void inputList(list &l)
{
    int n; //Number of Numbers
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        node* p = createNode(temp);
        addTail(l, p);
    }
}

int middleEvenPosition(list l)
{
    node* p = l.head;
    int count = 0;
    while(p != nullptr)
    {
        if(p->data % 2 == 0)
        {
            count++;
        }
        p = p->next;
    }
    return (int)(count / 2);
}

int main()
{
    list l;
    createList(l);
    inputList(l);
    cout << middleEvenPosition(l);
}