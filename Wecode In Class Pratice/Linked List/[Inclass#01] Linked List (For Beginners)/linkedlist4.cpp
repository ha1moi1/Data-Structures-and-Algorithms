
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct node
{
    int id, pop;
    double area;
    string name;
    node* link;
};

struct List
{
    node* head;
    node* tail;
    int n;
};

void Init(List& l)
{
    l.head = NULL;
    l.tail = NULL;
}

node* CreateNode()
{
    node* p = new node;
    int id, pop;
    double area;
    string name;

    p->id = id;
    p->pop = pop;
    p->name = name;
    p->area = area;
    
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

void inputListProvince(List &l, int n)
{
    l.n = n;
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

int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    cout<<"Provinces with a population of more than 1 million:"<<endl;
    outputProvincesMore1MillionPop(L);

    cout<<"The largest province:"<<endl;
    node *p = findProMaxArea(L);
    if(p) outputProvince(p->info);

    return 0;
}



