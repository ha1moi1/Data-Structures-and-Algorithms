#include <iostream>
using namespace std;

void input(int&, int*&);
void findMex(int, int*);
int main()
{
    int n;
    int* arr;

    input(n, arr);
    findMex(n, arr);

    delete[] arr;
    return 0;
}

void input(int& n, int*& arr)
{
    cin >> n;
    arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void findMex(int n, int* arr)
{
    int low = 0;
    int high = arr[0];

    for(int i = 0; i < n; i++)
    {
        
    }
}