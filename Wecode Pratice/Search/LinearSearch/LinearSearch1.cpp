#include <iostream>
using namespace std;

int LinearSearch(int, int, int*);

int main()
{
    int n, x;
    int* arr;

    cin >> n;
    arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> x;

    int result = LinearSearch(n, x, arr);
    if(result == -1) cout << -1 << endl;
    else
    {
        cout << result << endl 
             << result + 1 << endl 
             << n - result - 1 << endl 
             << n - result << endl;
    }
}

int LinearSearch(int n, int x, int* arr)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}