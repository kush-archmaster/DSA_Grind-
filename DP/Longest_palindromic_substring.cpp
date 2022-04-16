#include <bits/stdc++.h>
using namespace std;
/*
DP Approach (Tabular approach)
dp[i][j] = maxlen palindrome for substring with starting- ending indexes as i,j (values either 0 or 1)
1) base case (values which we know) --> diagonal values (0,0), (1,1)... all will store 1 since a character is itself a palindrome
2) when checking for string length of 2 (like dp[0][1], dp[1][2]) --> aa,ab --> then check s[i]==s[j], if yes then palindrome.
3) when string length > 2, (like dp[0][2]) -> aaa --> then check s[start]==s[end] and ispalindrome(i+1,j-1), if true then palindrome.
                                                        => (s[start]==s[end] && dp[i+1][j-1]==1)
s = aaaabbaa
     0   1   2   3   4   5   6   7
    -------------------------------
0|   1   1   1   1   0   0   0   0
1|       1   1   1   0   0   0   0
2|           1   1   0   0   0   1
3|               1   0   0   1   0
4|                   1   1   0   0
5|                       1   0   0
6|                           1   1
7|                               1

*/

string longestPalindromicSubstring(string s)
{
    //* Method1:  using Dynamic Programming --> O(N^2) space = O(N)
    //& get length of input string
    int size = s.length();
    string result = "";
    int start_index = 0;
    bool dp[size][size]; //& 2d array to store values for different substrings
    memset(dp, 0, sizeof(dp));

    int maxLength = 1; //& default value for each character, since it is itself a palindrome
    for (int i = 0; i < size; i++)
        dp[i][i] = 1;

    //& when length of the substring is 2
    for (int i = 0; i < size; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            start_index = 1; //& new start will be i, (this is important to put start here also, if the string is of length 2 only. then it will directly go to print the string)
            maxLength = 2;
        }
    }

    //& when length of substring can be greater than 3
    for (int gap = 3; gap <= size; gap++)
    {
        for (int i = 0; i < size - gap + 1; i++)
        {
            int j = i + gap - 1; //& ending index for that particular iteration
            if (dp[i + 1][j - 1] == 1 and s[i] == s[j])
            {
                dp[i][j] = 1;
                if (maxLength < gap)
                {
                    start_index = i; //& new starting index for longest substring possible till now
                    maxLength = gap; //& length of longest substring
                }
            }
        }
    }

    //& printing the substring
    for (int i = start_index; i <= start_index + maxLength - 1; i++)
        result += s[i];

    return result;
}

int expandfromMiddle(string s, int left, int right)
{
    if ((s == "") || left > right)
        return 0;

    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        left--;
        right++;
    }

    return (right - left + 1);
}

string longestPalindromicSubstring_Expand(string s)
{
    //* Method2:  Expanding Around Center -- O(N^2) - space O(1)
    if (s.length() < 1)
        return "";

    int start_index = 0, maxLength = 0, end_index = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int length_when_middle_character = expandfromMiddle(s, i, i);      // string = "racecar" --> only one element e at middle
        int length_when_normal = expandfromMiddle(s, i, i + 1);            // string = "aabbaa" --> no element only occuring once
        maxLength = max(length_when_middle_character, length_when_normal); // maxLength for that particular iteration

        // when new max length is found then we will update our current boundaries
        if (maxLength > (end_index - start_index))
        {
            start_index = i - ((maxLength - 1) / 2);
            end_index = i + (maxLength / 2);
        }
    }

    return s.substr(start_index, maxLength);
}

int main(int argc, char *argv[])
{
    string s = "abab";
    cout << "Dynamic Programming: " << longestPalindromicSubstring(s) << endl;
    //  << "Expand Around Center: " << longestPalindromicSubstring_Expand(s) << endl;
    return EXIT_SUCCESS;
}