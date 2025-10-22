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
    node* p = new node;
    if(!p) return nullptr;
    p->data = x;
    p->next = nullptr;
    return p;
}

void addHead(list &l, node* p)
{
    if(!l.head)
    {
        l.head = l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}

void input(list &l)
{
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(x >= 90)
        {
            node *p = createNode(x);
            addHead(l, p);
        }
    }
}

void display(list l)
{
    node *p = l.head;
    int count = 0;
    while(p && (count < 10))
    {
        cout << p->data << " ";
        count++;
        p = p->next;
    }
    cout << "END";
}

int main()
{
    list l;
    createList(l);

    input(l);
    display(l);
}