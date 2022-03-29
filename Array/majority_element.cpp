#include <bits/stdc++.h>
using namespace std;

int majority(vector<int> &nums)
{
    int size = nums.size();
    int majority_element = nums[0];
    unsigned int count = 1; //& considering first el frequency

    for (int i = 1; i < size; i++)
    {
        if (nums[i] == majority_element)
            count++;
        else
            count--;
        //* if count turns out to be zero, hence the majority of previous el is over, now new majority will be chosen!
        if (count == 0)
        {
            majority_element = nums[i];
            count = 1; //& frequency of new majority candidate
        }
    } //? end of for loop

    return majority_element;
}

int main(int argc, char *argv[])
{
    //*considering that the majority element exists in the array
    vector<int> nums = {1, 2, 3, 3, 3, 5, 5, 5, 5, 6};
    int majority_element = majority(nums);

    cout << majority_element << endl;
    return EXIT_SUCCESS;
}