#include <iostream>
using namespace std;

int BinarySearch(int, int, int*);

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
    int result = BinarySearch(n, x, arr);
    delete[] arr;
}

int BinarySearch(int n, int x, int* arr)
{
    int low = 0, high = n - 1, count = 0;

    while(low <= high)
    {
        int middle = low + (high - low) / 2;
        int value = arr[middle];
        
        if(value < x)
        {
            low = middle + 1;
        }
        else if(value > x)
        {
            high = middle - 1;
        }
        else
        {
            count++;
            cout << middle << endl << count;
            return middle;
        }
        count++;
    }
    cout << -1 << endl;
    return -1;
}