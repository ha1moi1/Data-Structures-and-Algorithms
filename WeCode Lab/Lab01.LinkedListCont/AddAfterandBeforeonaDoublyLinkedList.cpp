#include <iostream>
using namespace std;

struct DNode
{
    int info;
    DNode *pNext, *pPrev;
};

struct DList
{
    DNode *pHead, *pTail;
};

void init(DList &l)
{
    l.pHead = l.pTail = NULL;
}

DNode* createNode(int x)
{
    DNode* p = new DNode;
    if (p != NULL)
    {
        p->info = x;
        p->pNext = p->pPrev = NULL;
    }
    return p;
}

void addHead(DList &l, int x)
{
    DNode* p = createNode(x);
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead->pPrev = p;
        l.pHead = p;
    }
}

void addTail(DList &l, int x)
{
    DNode* p = createNode(x);
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        p->pPrev = l.pTail;
        l.pTail = p;
    }
}

void printList(DList l)
{
    if (l.pHead == NULL)
    {
        cout << "List is empty";
        return;
    }
    DNode* p = l.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}

void createList(DList &l)
{
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1) break;
        addTail(l, x);
    }
}

void addAfter(DList &l, int x, int y)
{
    if (l.pHead == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    DNode* q = l.pHead;
    while (q != NULL && q->info != y)
    {
        q = q->pNext;
    }
    if (q != NULL)
    {
        DNode* p = createNode(x);
        p->pNext = q->pNext;
        p->pPrev = q;
        if (q->pNext != NULL) q->pNext->pPrev = p;
        q->pNext = p;
        if (q == l.pTail) l.pTail = p;
    }
    else
    {
        cout << "\nCan't find the value " << y << endl;
    }
}

void addBefore(DList &l, int x, int y)
{
    if (l.pHead == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    DNode* q = l.pHead;
    while (q != NULL && q->info != y)
    {
        q = q->pNext;
    }
    if (q != NULL) 
    {
        DNode* p = createNode(x);
        p->pNext = q;
        p->pPrev = q->pPrev;
        if (q->pPrev != NULL) q->pPrev->pNext = p;
        q->pPrev = p;
        if (q == l.pHead) l.pHead = p;
    }
    else
    {
        cout << "\nCan't find the value " << y << endl;
    }
}


int main()
{
    DList L;
    init(L);
    int x, y, choice;

    cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n20. Exit"<<endl;

    while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers (x then y): ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers (x then y): ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;
        default:
            cout<<"\nInvalid choice!";
        }
    }

    return 0;
}
