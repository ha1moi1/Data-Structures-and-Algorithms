#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string* arr;
    string value;
    arr = new string[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> value;

    int low = 0, high = n - 1, middle, count = 0;
    while(low <= high)
    {
        count++;
        middle = low + (high - low) / 2;
        string target = arr[middle];

        if(target > value) high = middle - 1;
        else if(target < value) low = middle + 1;
        else
        {
            cout << middle << endl << count << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
