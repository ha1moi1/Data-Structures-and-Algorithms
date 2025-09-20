#include <iostream>
using namespace std;

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

    int resultsize = 0;
    int result[1];
    
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            result[resultsize] = i;
            resultsize++;
        }
    }

    if(resultsize == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    cout << resultsize << endl;
    for(int i = 0; i < resultsize; i++)
    {
        cout << result[i] << " " << result[i] + 1 << endl;
    }

    delete[] arr;
    return 0;
}