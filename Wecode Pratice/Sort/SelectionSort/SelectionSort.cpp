#include <iostream>
using namespace std;

void SelectionSort(int*, int);

int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    SelectionSort(a, n);
    
}

void SelectionSort(int* a, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[min] > a[j])
            {
                min = j;
            }
        }

        if(a[min] == a[i])
        {
            continue;
        }
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;

        for(int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}