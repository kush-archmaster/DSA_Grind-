#include <bits/stdc++.h>
using namespace std;

string zigzag_convert(string s, int numRows)
{
    if (numRows == 1)
        return s; //& if only one row, then the string will occupy the entire row

    string result = "";
    int position = numRows - 1, //& initially pos is to be set such so that entire first column can be filled
        len = s.length(),
        col_index, //& final column index till when characters are filled
        itr = 0;   //& iterator which will traverse the string and fill the matrix

    if (len == 1)
        return s; //& if theres only one character in the string

    char arr[numRows][len];
    memset(arr, ' ', sizeof(arr));

    for (int j = 0; j < len; j++) //& for corresponding column j
    {
        if (itr >= len)
        {
            col_index = j;
            break;
        }

        //& if position index is 0, it means new column is to be filled so again set pos = numRows-1
        if (position == 0)
            position = numRows - 1;

        //& if position value is one less than total numRows, it means we have to fill the column entirely
        if (position == numRows - 1)
        {
            for (int i = 0; i < numRows; i++)
            {
                if (itr < len)
                    arr[i][j] = s[itr++];
            }
        }
        //& when we have to fill the diagonal pattern of zigzag
        else
        {
            for (int i = 0; i < numRows; i++)
            {
                if (position == i && itr < len)
                {
                    arr[i][j] = s[itr++];
                }
            }
        }
        position--; //& decrement position and keep check of which character to fill next
    }

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < col_index; j++)
        {
            if (arr[i][j] != ' ')
                result += arr[i][j];
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << zigzag_convert(s, numRows) << endl;
    return EXIT_SUCCESS;
}