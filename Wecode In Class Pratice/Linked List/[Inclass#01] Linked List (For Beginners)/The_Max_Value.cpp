#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct node
{
    int info;
    node* link;
};

struct List
{
    node* head;
    node* tail;
};

void Init(List& l)
{
    l.head = NULL;
    l.tail = NULL;
}

node* CreateNode()
{
    node* p = new node;
    int info;
    cin >> info;
    p->info = info;
    p->link = NULL;
    return p;
}

void addTail(node* p, List &l)
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

void inputList(List &l, int n)
{
    if(n == 0) return;
    for(int i = 0; i < n; i++)
    {
        node* p = CreateNode();
        addTail(p, l);
    }
}

void outputList(List l)
{
    if(l.head == NULL && l.tail == NULL) cout << "List is empty";
    node* p;
    p = l.head;
    while(p != NULL)
    {
        cout << p->info << " ";
        p = p->link;
    }
}

node* findMax(List l)
{
    if (l.head == NULL)
    {
        cout << "List is empty";
        return NULL;
    }

    node* p = l.head;
    node* max = l.head;

    while (p != NULL)
    {
        if (p->info > max->info)
        {
            max = p;
        }
        p = p->link;
    }
    return max;
}

int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);


    cout<<"\nThe maximum value: ";
    node *p = findMax(L);
    if(p) cout<<p->info;

    return 0;
}