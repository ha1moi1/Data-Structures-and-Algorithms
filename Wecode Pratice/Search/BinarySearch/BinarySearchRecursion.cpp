#include <iostream>
using namespace std;

int NormalBinarySearch(int, int, int*);
int ReverseBinarySearch(int, int, int*);
int RecursionBinarySearch(int, int*, int, int);
int RecursionReverseBinarySearch(int, int*, int, int);


int main()
{
    int n, value;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> value;

    cout << RecursionReverseBinarySearch(value, arr, 0, n - 1);
}

int NormalBinarySearch(int n, int value, int* arr)
{
    int high = n - 1, low = 0;

    while(low <= high)
    {
        int middle = low + (high - low) / 2;
        int target = arr[middle];

        if(target > value) high = middle - 1;
        else if(target < value) low = middle + 1;
        else return middle;
    }
    return -1;
}

int ReverseBinarySearch(int n, int value, int* arr)
{
    int high = n - 1, low = 0;

    while(low <= high)
    {
        int middle = low + (high - low) / 2;
        int target = arr[middle];

        if(target < value) high = middle - 1;
        else if(target > value) low = middle + 1;
        else return middle;
    }
    return -1;
}

int RecursionBinarySearch(int value, int* arr, int low, int high)
{
    int middle = low + (high - low) / 2;
    int target = arr[middle];
    if(low > high)
    {
        return -1;
    }
    if(target > value)
    {
        return RecursionBinarySearch(value, arr, low, middle - 1);
    }
    else if(target < value)
    {
        return RecursionBinarySearch(value, arr, middle + 1, high);
    }
    else return middle;
}

int RecursionReverseBinarySearch(int value, int* arr, int low, int high)
{
    int middle = low + (high - low) / 2;
    int target = arr[middle];
    if(low > high)
    {
        return -1;
    }
    if(target < value)
    {
        return RecursionReverseBinarySearch(value, arr, low, middle - 1);
    }
    else if(target > value)
    {
        return RecursionReverseBinarySearch(value, arr, middle + 1, high);
    }
    else return middle;
}