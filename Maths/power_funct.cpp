#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    //& always ask interviewer if value of n can be negative
    //& edge case since n in negative INT_MIN if converted to positive will overflow -21789283 to 21789282
    //& and if we try to convert INT_MIN (-21789283) it is not excepted

    //& Binary Exponentiation
    //& to avoid size conflict take long long
    double answer = 1.0;
    long long num = n; //& creating a copy of n

    if (num < 0)
        num = num * (-1);

    while (num != 0)
    {
        if (num % 2 == 0)
        {
            x = (x * x);
            num /= 2;
        }
        else
        {
            answer = answer * x;
            num = num - 1;
        }
    }

    //& value of power is negative
    if (n < 0)
        answer = (double)1.0 / (double)answer;

    return answer;
}

int main()
{
    double num = 2.00000, power = 10;
    cout << pow(num, power) << endl;
    return EXIT_SUCCESS;
}

/*
*for example:
 *  2^10 = (2*2)^5   --- step1  (when n=10 -->even)
 *  4* (4)^5 =4 * [4 * 4^4]  --- step2 (when n=5 -->odd)
 *  4* 4^4 = 4* [(4*4)^2] -- step 3 (when n=4 -->even)
 *  4* (16)^2 =4* [(16*16)^1] = 256^1  -- step 4 (n=2 -->even)
 *  4* 256^1 = 4* [256 * (256)^0] (n=1 --> odd)
 *  4*256 = 1024

*  Generalisation:

 *   if n%2==0  --> (x*x) =>n = n/2
 *  if n%2==1  --> (ans = ans*x) =>n = n-1
 *   // stop when n==0
 *   TC = O(log n)
*/