#include <iostream>
using namespace std;

void BubbleSort(int*, int);

int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    BubbleSort(a, n);
}

void BubbleSort(int* a, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                int temp = a[j + 1];
                a[j + 1] = a[j]; 
                a[j] = temp;
                for(int z = 0; z < n; z++)
                {
                    cout << a[z] << " ";
                }
                cout << endl;
            }
        }
        
    }
}