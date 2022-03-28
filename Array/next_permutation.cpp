#include <bits/stdc++.h>
using namespace std;

/*
*Method1: inbuilt next_permutation() function

*Method2: Generate all possible permutations and then check in the array

^(discussed)
*Method3: Algorithm to find next permutation
*       --> linearly traverse from the back, while traversing, find first index i such that
*          arr[i]<arr[i+1]  = mark it as first index, ind1;
*        --> again traverse from back and find the element which is having value > arr[i] = mark it as second index, ind2
*        --> swap(arr[ind1], arr[ind2])
*        --> reverse the array after ind1  --> from ind1+1 to end
*/
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void next_perm(vector<int> &nums)
{
    int size = nums.size(), index1, index2;
    //* Step1
    for (int index1 = size - 2; index1 >= 0; index1--)
    {
        if (nums[index1] < nums[index1 + 1])
            break;
    }

    //*edge case, if numbers are in descending order 5,4,3,2,1 --next--> 1,2,3,4,5
    if (index1 < 0)
        reverse(nums.begin(), nums.end());
    else
    {
        //* Step2
        for (int index2 = size - 1; index2 > index1; index2--)
        {
            if (nums[index2] > nums[index1])
                break;
        }
        //* Step3
        swap(&nums[index1], &nums[index2]);
        //* Step4
        reverse(nums.begin() + index1 + 1, nums.end());
    }
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3};
    next_perm(nums);

    for (int i = 0; i < (int)nums.size(); i++)
    {
        cout << nums[i] << " ";
    } //? end of for loop
    return EXIT_SUCCESS;
}
