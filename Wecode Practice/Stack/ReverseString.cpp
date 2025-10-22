#include <iostream>
#include <stack>
#include <string>
using namespace std;

string Reverse(string s)
{
    stack<char> st;
    for(char c : s)
    {
        st.push(c);
    }

    string result;
    while(!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

int main()
{
    string s;
    getline(cin, s);
    cout << Reverse(s) << endl;
}