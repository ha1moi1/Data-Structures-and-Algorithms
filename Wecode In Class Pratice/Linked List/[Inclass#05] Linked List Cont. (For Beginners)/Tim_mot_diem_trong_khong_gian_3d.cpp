#include <iostream>
#include <cmath>

using namespace std;

typedef struct Point3D
{
    float x, y, z;
}p3d;

struct node
{
    p3d data;
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

node* CreateNode(p3d data)
{
    node *p = new node;
    if(p == NULL) return NULL;
    p->link = NULL;
    p->data = data;
    return p;
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

void input(List &l, int n)
{
    for(int i = 0; i < n; i++)
    {
        p3d data;
        cin >> data.x >> data.y >> data.z;
        node* p = CreateNode(data);
        addTail(l, p);
    }
}

int searchList(List l, node* x)
{
    node *p = l.head;
    int index = 0;
    while(p != NULL)
    {
        if((p->data.x == x->data.x) &&
           (p->data.y == x->data.y) &&
           (p->data.z == x->data.z)) 
                return index;
        index++;
        p = p->link;
    }
    return -1;
}

node* getNodeAt(List l, int pos)
{
    node* p = l.head;
    int index = 0;
    
    while(p != NULL && index < pos)
    {
        p = p->link;
        index++;
    }
    return p;
}

int main()
{
    List l1, l2;
    CreateList(l1);
    CreateList(l2);
    int n;
    cin >> n;
    input(l1, n);
    int m;
    cin >> m;
    input(l2, m);

    node *p = new node;
    for(int i = 0; i < m; i++)
    {
        node *q = getNodeAt(l2, i);
        int index = searchList(l1, q);
        if (index == -1) cout << "KHONG" << endl; 
        else cout << index << endl;
    }
}