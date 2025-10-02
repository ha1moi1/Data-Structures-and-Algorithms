#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};
struct List
{
    node *head,*tail;
};
node* getNode(int x)
{
    node *p=new node;
    if (p)
    {
        p->info=x;
        p->next=NULL;
    }
    return p;
}
void Init (List &L)
{
    L.head=L.tail=NULL;
}



void addTail(List &L, int x)
{
    node* p = getNode(x);
    if (L.head==NULL)
        L.head=L.tail=p;
    else
    {
        L.tail->next=p;
        L.tail = p;
    }
}

void outputList(List L)
{
    node *p=L.head;
    while (p)
    {
       cout<<p->info<<" ";
        p=p->next;
    }
    cout << endl;
}

void addHead(node* p, List &l)
{
    if(l.head == NULL) 
    {
        l.head = p;
        l.tail = l.head;
    }
    else 
    {
        p->next = l.head;
        l.head = p;
    } 
}

void insertAfterQ(List &l, node* p, node* q)
{
    if(q != NULL)
    {
        p->next = q->next;
        q->next = p;
        if(l.tail == q) l.tail = p;
    }
    else addHead(p, l);
}

void insertList(List &l, int x)
{
    node* temp = getNode(x);

    if(l.head == NULL)
    {
        l.head = l.tail = temp;
        return;
    }

    if(x <= l.head->info)
    {
        addHead(temp, l);
        return;
    }

    node* p = l.head;
    while(p->next != NULL && p->next->info < x)
    {
        p = p->next;
    }

    if(p == l.tail)
    {
        addTail(l, x);
        return;
    }

    insertAfterQ(l, temp, p);
}

void inputList(List &L,int n)
{

    int x;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        insertList(L,x);
        outputList(L);
    }
}

int main()
{
    List L;
    Init(L);
    int n,x; cin>>n;
    inputList(L,n);
    return 0;
}