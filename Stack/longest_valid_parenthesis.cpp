#include <bits/stdc++.h>
using namespace std;

/*
    Input: str = "(()()"

    Initialize result as 0 and stack with one item -1.

    For i = 0, str[0] = '(', we push 0 in stack

    For i = 1, str[1] = '(', we push 1 in stack

For i = 2, str[2] = ')', currently stack has
[-1, 0, 1], we pop from the stack and the stack
now is [-1, 0] and length of current valid substring
becomes 2 (we get this 2 by subtracting stack top from
current index).

Since the current length is more than the current result,
we update the result.

For i = 3, str[3] = '(', we push again, stack is [-1, 0, 3].
For i = 4, str[4] = ')', we pop from the stack, stack
becomes [-1, 0] and length of current valid substring
becomes 4 (we get this 4 by subtracting stack top from
current index).
Since current length is more than current result,
we update result.

*/

int longestValidParentheses(string s)
{
    int result = 0;
    int size = s.length();
    stack<int> st;
    st.push(-1); //&& Create a stack and push -1 as initial index to it.

    //& Traverse all characters of given string
    for (int i = 0; i < size; i++)
    {
        //& If opening bracket, push index of it
        if (s[i] == '(')
            st.push(i);

        //& If closing bracket, i.e.,str[i] = ')'
        else
        {
            //& Pop the previous opening bracket's index
            if (!st.empty())
            {
                st.pop();
            }

            if (!st.empty())
                result = max(result, i - st.top()); //& Check if this length formed with base of current valid substring is more than max so far

            //& If stack is empty. push current index as
            //& base for next valid substring (if any) -- this index would act as -1, index where there was problem
            else
                st.push(i);
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    string s = "()()()))";
    cout << longestValidParentheses(s) << endl;
    return EXIT_SUCCESS;
}