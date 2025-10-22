#include <iostream>
#include <string>
#define MAX 2000
using namespace std;

struct Stack
{
    char arr[MAX];
    int index;
};

int isValid(string s)
{
    if (s.empty()) return 1;
    
    Stack st;
    st.index = -1;

    for (char c : s)
    {

        if (c == '(' || c == '{' || c == '[')
        {
            st.arr[++st.index] = c;
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (st.index == -1) return 0;

            char top = st.arr[st.index--];

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
            {
                return 0;
            }
        }
    }

    if(st.index == -1) return 1;
    else return 0;
}

int main()
{
    string expr;
    cin >> expr;
    cout << isValid(expr);
    return 0;
}
