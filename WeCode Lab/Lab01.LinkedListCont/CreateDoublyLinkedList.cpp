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

int main()
{
    DList L;
    init(L);
    int choice;

    cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
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
        case 20:
            cout<<"\nGOOD BYE";
            return 0;
        }
    }
    return 0;
}
