#include <iostream>
#include <vector>
using namespace std;

vector<int> LinearSearch(int, int, int*);

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

    vector<int> result = LinearSearch(n, x, arr);
    int size = result.size();
    if(size == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << size << endl;
        for(int i = 0; i < size; i++)
        {
            cout << result[i] << " " << result[i] + 1 << endl;
        }
    }
    delete []arr;
    return 0;
}

vector<int> LinearSearch(int n, int x, int* arr)
{
    vector<int> result;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            result.push_back(i);
        }
    }
    return result;
}