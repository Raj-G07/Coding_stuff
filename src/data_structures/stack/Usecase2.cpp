// Evaluation of Expressions using Stacks

#include <stack>
#include <string>
#include <iostream>
using namespace std;

int evaluatePostfix(string exp)
{
    stack<int> st;
    for (auto c : exp)
    {
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch (c)
            {
            case '+':
                st.push(val1 + val2);
                break;
            case '-':
                st.push(val1 - val2);
                break;
            case '*':
                st.push(val1 * val2);
                break;
            case '/':
                st.push(val1 / val2);
                break;
            }
        }
    }
    return st.top();
}

// Postfix Evaluation: O(n)