#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct pro
{
    int id;
    string name;
    int pop;
    double area;
};

struct node
{
    pro info;
    node* next;
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

void inputProvinceInfo(pro &info)
{
    cin >> info.id;
    cin.ignore();
    getline(cin, info.name);
    cin >> info.pop;
    cin >> info.area;
}

node* createNode(pro info)
{
    node* p = new node;
    p->info = info;
    p->next = NULL;
    return p;
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
        l.tail->next = p;
        l.tail = p;
    }
}

void inputListProvinces(List &l)
{
    int n;
    cin >> n;
    pro info;

    for(int i = 0; i < n; i++)
    {
        inputProvinceInfo(info);
        node* p = createNode(info);
        addTail(l, p);
    }
}

void outputProvince(node* p)
{
    cout << p->info.id << "\t" << 
                p->info.name << "\t" <<
                p->info.pop << "\t" <<
                p->info.area << endl;
}

void outputProvince(pro info)
{
    cout << info.id << "\t" << 
            info.name << "\t" <<
            info.pop << "\t" <<
            info.area << endl;
}

void outputListProvinces(List l)
{
    node*p = l.head;
    while(p != NULL)
    {
        outputProvince(p);
        p = p->next;
    }
}

void outputProvincesMore1MillionPop(List l)
{
    node* p = l.head;
    while(p != NULL)
    {
        if(p->info.pop > 1000)
        {
            outputProvince(p);
        }
        p = p->next;
    }
}

node* findProMaxArea(List l)
{
    node* p = l.head->next;
    node* result = l.head;
    double max = l.head->info.area;
    while(p != NULL)
    {
        if(p->info.area > max)
        {
            result = p;
        }
        p = p->next;
    }
    return result;
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