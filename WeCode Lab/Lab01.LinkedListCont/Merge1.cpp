#include <iostream>
using namespace std;

struct node
{
    int data;
    node* pNext;
};

struct List
{
    node* head;
    node* tail;
};

void Init(List &l)
{
    l.head = NULL;
    l.tail = NULL;
}

node* createNode(int x)
{
    node* p = new node;
    if(p == NULL) return NULL;
    p->data = x;
    p->pNext = NULL;
    return p;
}

void addTail(List& l, node* p)
{
    if(l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        l.tail->pNext = p;
        l.tail = p;
    }
}

void inputList(List &l, int n)
{
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        node* p = createNode(temp);
        addTail(l, p);
    }
}

void mergeList(List l1, List l2, List& l3)
{
    node *p = l1.head;
    node* q = l2.head;
    
    node dummy; 
    node *s = &dummy;  
    dummy.pNext = NULL;
    
    while(p != NULL && q != NULL)
    {
        if(p->data <= q->data)
        {
            s->pNext = createNode(p->data);
            p = p->pNext;
        }
        else
        {
            s->pNext = createNode(q->data);
            q = q->pNext;
        }
        s = s->pNext;
    }
    while(p != NULL)
    {
        s->pNext = createNode(p->data);
        p = p->pNext;
        s = s->pNext;
    }
    while(q != NULL)
    {
        s->pNext =  createNode(q->data);
        q = q->pNext;
        s = s->pNext;
    }

    l3.head = dummy.pNext;
}


void outputList(List L)
{
	for(node* p = L.head; p!=NULL; p=p->pNext)
		cout << p->data << " ";

}
int main()
{
    List L1, L2, L3;
    Init(L1);Init(L2);Init(L3);

    int n,m; cin>>n;
    inputList(L1,n);
    cin>>m;
    inputList(L2,m);


    mergeList(L1,L2,L3);
    outputList(L3);

    return 0;
}
