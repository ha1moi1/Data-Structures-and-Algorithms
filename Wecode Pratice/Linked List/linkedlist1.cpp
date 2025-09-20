#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct node
{
    int data;
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
    int data;
    cin >> data;
    p->data = data;
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
        cout << p->data << " ";
        p = p->link;
    }
}

node* search(List l, int x)
{
    node* p;
    p = l.head;
    while((p != NULL) && (p->data != x))
    {
        p = p->link;
    }
    return p;
}

void outputGreaterThan(List l, int m)
{
    if(l.head == NULL && l.tail == NULL) cout << "List is empty";
    node* p;
    p = l.head;
    bool found = false;
    while((p != NULL))
    {
        if(p->data > m)
        {
            found = true;
            cout << p->data << " ";
        }
        p = p->link;
    }
    if(!found) cout << "None";
}

int main()
{
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach
    int n; cout<<"Enter a number: "; cin>>n; // Nhap so luong phan tu cua ds
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n); // Nhap 1 day gom n so va luu vao ds. Phan tu moi duoc them vao cuoi ds
    cout<<"\nThe created Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"


    cout<<"\nEnter a number: "; int m; cin>>m;
    cout<<"\nValues greater than "<<m<<": ";
    outputGreaterThan(L,m);
    /*Xuat tat ca cac gia tri duoc luu trong ds lon hon m.
     Neu ds rong thi xuat thong bao "List is empty".
     Neu ds khong rong nhung khong co gia tri thoa yeu cau thi xuat "None"*/

    return 0;
}
