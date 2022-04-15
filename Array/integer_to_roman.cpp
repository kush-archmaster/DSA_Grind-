#include <bits/stdc++.h>
using namespace std;

/* possible combinations formed

*  M  - 1000
*  CM - 900
*  D  - 500
*  CD - 400
*  C  - 100
*  XC - 90
*  L  - 50
*  XL - 40
*  X  - 10
*  IX - 9
*  V  - 5
*  IV - 4
*  I  - 1


  */

/*
 & Method 1 usinf if else conditional blocks
            string ans = "";
            while(num>=1000)
            {
                ans+="M";
                num-=1000;
            }
            if(num>=900)
            {
                ans+="CM";
                num-=900;
            }

            while(num>=500)
            {
                ans+="D";
                num-=500;
            }
            if(num>=400)
            {
                ans+="CD";
                num-=400;
            }

            while(num>=100)
            {
               ans+="C";
                num-=100;
            }
            if(num>=90)
            {
                ans+="XC";
                num-=90;
            }

            while(num>=50)
            {
               ans+="L";
                num-=50;
            }
            if(num>=40)
            {
                ans+="XL";
                num-=40;
            }

            while(num>=10)
            {
                ans+="X";
                num-=10;
            }
            if(num>=9)
            {
                ans+="IX";
                num-=9;
            }

            while(num>=5)
            {
                ans+="V";
                num-=5;
            }
            if(num>=4)
            {
               ans+="IV";
                num-=4;
            }

             while(num>=1)
            {
                ans+="I";
                num-=1;
            }

*/

string intToRoman(int num)
{
    //* Method 2 using mapping
    vector<int> intValues = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> romanValues = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string ans = ""; // answer
    int size = intValues.size();
    for (int i = 0; i < size; i++)
    {
        while (num >= intValues[i])
        {
            ans += romanValues[i];
            num -= intValues[i];
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    cout << intToRoman(65) << endl;
    return EXIT_SUCCESS;
}