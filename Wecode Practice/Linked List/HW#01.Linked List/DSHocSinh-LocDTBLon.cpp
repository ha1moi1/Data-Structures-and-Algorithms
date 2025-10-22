#include <iostream>
#include <string>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x){
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;;
}

struct Node {
    Hocsinh data;
    Node * next;
};

struct List {
    Node * head, * tail;
};

void Output(List ds) {
    Node *p = ds.head;
    if (p == NULL) {
        cout << "EMPTY";
    }
    while(p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}

Node* CreateNode(Hocsinh hs)
{
    Node* p = new Node;
    if(!p) return nullptr;
    p->data = hs;
    p->next = NULL;
    return p;
}

void AddTail(List &ds, Node* p)
{
    if(!ds.head)
    {
        ds.head = ds.tail = p;
    }
    else
    {
        ds.tail->next = p;
        ds.tail = p;
    }
}

void Input(List &ds)
{
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        Hocsinh hs;
        InputElement(hs);
        Node* p = CreateNode(hs);
        AddTail(ds, p);
    }
}

void CreateList(List &ds)
{
    ds.head = ds.tail = nullptr;
}

double getAverage(Hocsinh hs)
{
    return (hs.Anh + hs.Hoa + hs.Ly + hs.Toan + hs.Van + hs.Sinh) / 6;
}

void findExcellentStudent(List ds, List &xs)
{   
    Node* p = ds.head;
    while(p)
    {
        double avg = getAverage(p->data);
        if(avg >= 9.0)
        {
            Node* q = CreateNode(p->data);
            AddTail(xs, q); 
        }
        p = p->next;
    }
}
int main()
{
    List ds;
    CreateList(ds);
    Input(ds);

    List xs;
    CreateList(xs);
    findExcellentStudent(ds, xs);
    Output(xs);
}