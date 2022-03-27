#include <bits/stdc++.h>
using namespace std;

int roman_to_integer(string s)
{
    //* initialise hash map for roman numbers
    unordered_map<int, int> map;
    int ans = 0;
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    for (int i = 0; i < s.length();)
    {
        //& check if the letter is smaller than the next one (like IX) in that case subtract the i-th letter from (i+1)-th letter
        if ((i + 1) < s.length() && map[s[i]] < map[s[i + 1]])
        {
            ans += (map[s[i + 1]] - map[s[i]]);
            i += 2;
        }
        //& normally add the map value of that letter to the result
        else
        {
            ans += map[s[i]];
            i++;
        }
    }

    return ans;
}

int main(int argc, char *argv[])
{
    string s = "XXVII";
    cout << roman_to_integer(s) << endl;
    return EXIT_SUCCESS;
}