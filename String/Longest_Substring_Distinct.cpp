#include <bits/stdc++.h>
using namespace std;

bool isUnique(string s, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (s[i] == s[j])
            {
                return false;
                break;
            }
        }
    }
    return true;
}

int lengthOfLongestSubstring(string s)
{
    //& compute the maxend(j) --> length of longest substring that has distinct characters that end with j
    //&  result will be max(maxend(j)) where 0<=j<=s.length()-1
    /*
     * For example:
     * s = "abcabcbb"

*         a b c a b c b b
*  maxend 1 2 3 3 3 3 2 1
*  output = 3

*  Note:  maxEnd(j) = {
*                      1+maxend(j-1)   -> if str[j] is not present in maxend(j)  it is distinct

*                      j-prev(str[j])+1  -> where prev(str[j]) is previous index of character str[j]
*                     }
*        if prev(str(j)) < i, it means it is not present in the substring from i to j, else it is present
*     */

    int n = s.length();
    vector<int> previous_index(256, -1); //&  initialising all the characters initial indexes as -1
    int start_index = 0;                 //& since we will start from first letter of the string
    int result = 0;

    for (int curr_index = 0; curr_index < n; curr_index++)
    {
        start_index = max(start_index, previous_index[s[curr_index]] + 1); //& to exclude the previous occurrence of the character if it is between tha start and curr, like abcb , here will be start from index 2 i.e 'c'

        int maxEnding = curr_index - start_index + 1; //& length for that substring
        result = max(result, maxEnding);              //& maximum length of the distinct substring

        previous_index[s[curr_index]] = curr_index; //& updating the previous index for that character
    }

    for (int i = 0; i <= n - result; i++)
    {
        int j = i + result - 1;
        if (isUnique(s, i, j))
        {
            //& cout << "Start : " << i << " End: " << j << endl;
            if ((j - i + 1) == result)
            {
                cout << s.substr(i, result) << endl;
            }
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    string s = "abcdeffghijkkklmnop";
    cout << lengthOfLongestSubstring(s) << endl;
    return EXIT_SUCCESS;
}