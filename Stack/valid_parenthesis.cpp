#include <bits/stdc++.h>
using namespace std;

//& utility function to check bracket pairs
bool isMatching(char x, char y)
{
    if ((x == '(' && y == ')') || (x == '{' && y == '}') || (x == '[' && y == ']'))
    {
        return true;
    }
    return false;
}

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        //& if opening brackt is encountered, we push it in stack
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if (!st.empty())
            {
                //& check if the top of stack is of same type
                if (!isMatching(st.top(), s[i]))
                    return false;

                st.pop(); //& if matching pair then remove the corresponding opening brackt
            }
            else
            {
                st.push(i);
            }
        }
    }
    //& if stack is not empty is means opening parenthesis are not balanced
    if (!st.empty())
        return false;

    return true;
}

int main(int argc, char *argv[])
{
    string s = "[{()}]()";
    cout << boolalpha << isValid(s) << endl;
    return EXIT_SUCCESS;
}