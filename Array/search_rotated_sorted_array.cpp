#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        //? if element next to mid is smaller then mid is the pivot element
        if (mid < high && nums[mid] > nums[mid + 1])
            return mid;

        //? if element to left of mid is greater than mid then (mid-1) is the pivot el
        if (mid > low && nums[mid - 1] > nums[mid])
            return mid - 1;

        //? if nums[low] is greater than mid, then search  at left half of array else right half
        if (nums[low] >= nums[mid])
            return findPivot(nums, low, mid - 1);

        //? else search in right part of the mid
        return findPivot(nums, mid + 1, high);
    }
    return -1;
}

int binarySearch(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
        return -1;

    if (low == high)
        return low;
    //* binary search logic
    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
        return mid;

    else if (target > nums[mid])
        return binarySearch(nums, mid + 1, high, target);

    return binarySearch(nums, low, mid - 1, target);
}

int solve(vector<int> &nums, int target)
{
    int size = nums.size();
    //& finding the pivot index around which the array is rotated
    int pivot = findPivot(nums, 0, size - 1);

    //& if array is not rotated
    if (pivot == -1)
        return binarySearch(nums, 0, size - 1, target);

    //& if target is at pivot index
    if (nums[pivot] == target)
        return pivot;

    //& if first element of array is smaller than target, then it means the target is present before the pivot element
    else if (nums[0] <= target)
        return binarySearch(nums, 0, pivot - 1, target);

    //& if first element of array is greater than target, then it means the target is present after the pivot element
    return binarySearch(nums, pivot + 1, size - 1, target);
}

int main(int argc, char *argv[])
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 2;

    //* Calling the solve function
    cout << solve(nums, target) << endl;

    return EXIT_SUCCESS;
}
