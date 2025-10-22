
#include <iostream>
#include <stack>

using namespace std;

void DecimaltoBinary(int n)
{
    stack<int> S;
    if(n == 0)
    {
        cout << 0;
        return;
    }
    while(n != 0)
    {
        int c = (n % 2);
        S.push(c);
        n /= 2;
    }

    while(!S.empty())
    {
        cout << S.top();
        S.pop();
    }
}
int main()
{

    int n;
    cin>>n;
    DecimaltoBinary(n);
    return 0;
}



