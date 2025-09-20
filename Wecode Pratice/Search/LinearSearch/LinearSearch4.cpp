#include <iostream>
using namespace std;

void EqualDiverseTeams(int*&);

int main()
{
    int n;
    int** arr;
    cin >> n;
    arr = new int*[n];

    for(int i = 0; i < n; i++)
    {
        EqualDiverseTeams(arr[i]);
    }
}

void EqualDiverseTeams(int*& arr)
{
    int size, x, count = 0, num[10];
    cin >> size >> x;
    arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    
}