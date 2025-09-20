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

node* findElement(List l, int i)
{
    if(l.head == NULL && l.tail == NULL)
    {
        cout << "List is empty";
        return NULL;
    }
    node* p = l.head;
    int index = 0;
    
    while(p != NULL)
    {
        if(index == i)
        {
            return p;
        }
        p = p->link;
        index++;
    }
    if(p == NULL)
    {
        cout << "The index is invalid";
        return NULL;
    }
    cout << "List is empty";
    return NULL;
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

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<": ";
    node *p = findElement(L,i);
    if(p) cout<<p->info;


    return 0;
}
