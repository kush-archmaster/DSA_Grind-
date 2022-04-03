#include <bits/stdc++.h>
using namespace std;

//* Method 1 --> Iterative
/*
 *Iterative solution using two array traversals
 *maintain count_start, count_end --> if we skip one character from either side, increment the count.
 *Remember the count shouldnt go beyond 1, since we can skip one char and check whether it will turn out to be a palindrome.
 */
bool validate_iterative(string s)
{
    int start = 0,
        end = s.length() - 1,
        count1 = 0,
        count2 = 0;

    //& considering character to be removed is from the left part --> ab f eba
    while (start < end)
    {
        if (s[start] != s[end])
        {
            start++;
            count1++;
        }
        else
        {
            start++;
            end--;
        }
    }

    //&considering character is removed from right part --> abe f ba
    start = 0, end = s.length() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
        {
            end--;
            count2++;
        }
        else
        {
            start++;
            end--;
        }
    }

    //^ either of the counts is 1 it means only one character has been skipped, or if both are 0 , then it was a valid palindrome only
    if (count1 == 1 || count2 == 1)
        return true;
    if (count1 == 0 || count2 == 0)
        return true;

    return false;
}

//^------------------------------------------------------------------------------------------------------------------------

//* Method2 --> Recursive
/*
 * Recursive solution, where we check that if start != end , then if skipping one character from start/end would get
 * the palindrome or not.
 */
bool isPalindrome(string s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

bool validate_recursive(string s1)
{
    int start = 0,
        end = s1.length() - 1;

    while (start < end)
    {
        if (s1[start] != s1[end])
        {
            return (isPalindrome(s1, start + 1, end) || isPalindrome(s1, start, end - 1));
        }
        start++;
        end--;
    }

    return true;
}

int main(int argc, char *argv[])
{
    string s = "abjieeiba",
           s1 = "aabbcceybbaa";
    cout << "Iterative :" << boolalpha << validate_iterative(s) << endl
         << "Recursive :" << boolalpha << validate_recursive(s1) << endl;
    return EXIT_SUCCESS;
}