#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/') return true;
    return false;
}

int main()
{
    string s;
    getline(cin, s);
    stack<int> st;
    vector<char> v;
    for(char c : s)
    {
        if(c == ' ') continue;
        if('0' <= c && c <= '9') st.push(c - '0');
        else if(isOperator(c))
        {
            if(st.size() < 2)
            {
                cout << "KHONG HOP LE";
            }
            float result;
            float second = st.top(); st.pop();
            float first = st.top(); st.pop();
            switch(c)
            {
                case '+':
                {
                    result = first + second;
                    break;
                }
                case '-':
                {
                    result = first - second;
                    break;
                }
                case '*':
                {
                    result = first * second;
                    break;
                }
                case '/':
                {
                    if(second == 0)
                    {
                        cout << "KHONG HOP LE";
                        exit(0);
                    }
                    result = first / second;
                    break;
                }

            }
            st.push(result);
        }
    }
    cout << st.top();
}