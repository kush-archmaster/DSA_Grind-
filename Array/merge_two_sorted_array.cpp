/*
 *You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 *Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 *The final sorted array should not be returned by the function, but instead be stored inside the array nums1
 */

#include <bits/stdc++.h>
using namespace std;

//* traversing from rightmost side to fill the nums1 comparing both sides
void mergeSort(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int end_nums1 = m - 1, //& rightmost element in nums1 (before trailing zeroes)
        end_nums2 = n - 1, //& rightmost element in nums2
        final_index = m + n - 1;

    //& considering nums2 of smaller length
    while (end_nums2 >= 0)
    {
        if (end_nums1 >= 0 && nums1[end_nums1] > nums2[end_nums2])
        {
            nums1[final_index--] = nums1[end_nums1--];
        }
        else
        {
            nums1[final_index--] = nums1[end_nums2--];
        }
    }
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0},
                nums2 = {2, 5, 6};

    mergeSort(nums1, nums1.size(), nums2, nums2.size());

    for (auto i : nums1)
    {
        cout << i << " ";
    } //? end of for loop
    return EXIT_SUCCESS;
}