// Balanced Parentheses Check using Stack
#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s)
{
    stack<char> st;
    for (auto c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return false;
            char top = st.top();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

// Balanced Parentheses Check: O(n), where n is the length of the expression