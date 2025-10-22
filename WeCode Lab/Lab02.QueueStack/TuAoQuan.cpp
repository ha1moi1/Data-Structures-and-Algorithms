#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Clothes
{
    string shirt;
    int size;
};

struct node
{
    Clothes c;
    node* next;
};

struct Stack
{
    node* head;
    node* tail;
};

void Init(Stack &s)
{
    s.head = nullptr;
    s.tail = nullptr;
}

node* CreateNode(Clothes c)
{
    node* p = new node;
    if(!p) return nullptr;

    p->c = c;
    p->next = nullptr;
    return p;
}

void addHead(Stack &S, node* p)
{
    if(S.head == NULL) 
    {
        S.head = p;
        S.tail = S.head;
    }
    else 
    {
        p->next = S.head;
        S.head = p;
    } 
}

void Push(Stack &S, Clothes x)
{
    node *p = CreateNode(x);
    addHead(S, p);
}

Clothes Top(Stack S)
{
    return S.head->c;
}

void Pop(Stack &S)
{
    S.head = S.head->next;
}

void Input(Stack &S)
{
    Clothes c;
    while(1)
    {
        cin >> c.shirt;
        if(c.shirt == "-1") break;
        else
        {
            cin >> c.size;
            Push(S, c);
        }
    }
}

void getTopAfterPopX(Stack S)
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        Pop(S);
    }

    Clothes result = Top(S);
    cout << result.shirt << " " << result.size << endl;
}

int main()
{
    Stack S;
    Input(S);
    getTopAfterPopX(S);
}