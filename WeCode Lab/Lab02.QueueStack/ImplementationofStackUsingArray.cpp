#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};

void Init(Stack &s)
{
    s.n = 0;
}

bool isEmpty(Stack S)
{
    return S.n == 0;
}

bool isFull(Stack S)
{
    return S.n == MAX;
}

void Push(Stack &s, int x)
{
    if (isFull(s)) return;
    s.arr[s.n++] = x;
}

void printStack(Stack s)
{
    if(isEmpty(s))
    {
        cout << "Stack is empty";
    }
    for(int i = 0; i < s.n; i++)
    {
        cout << s.arr[i] << " ";
    }
    cout << endl;
}

int Top(Stack S)
{
    if (isEmpty(S)) return NULLDATA;
    return S.arr[S.n - 1];
}

void Pop(Stack &S)
{
    if (isEmpty(S)) return;
    S.n--;
}

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    for (int i= 1; i<=n; i++)
    {
        cin>>x;
        Push(S,x);
    }
    cout<<"Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    Pop(S);
    cout<<"\nUpdated Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    return 0;
}