#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &nums, int target, int low, int high)
{
    if (low > high)
        return -1;
    //* calculating the mid for the sorted array
    int mid = low + (high - low) / 2;

    //* condition for element to be first occurrence
    if (mid > low && (nums[mid] == target && nums[mid - 1] != nums[mid]))
        return mid;

    //* if first element is equal to target, then it is the first occurring element
    if (nums[low] == target)
        return low;

    //* check if mid element is greater or equal to target, then move to left part
    if (nums[mid] >= target)
        return firstOccurrence(nums, target, 0, mid - 1);
    else
        return firstOccurrence(nums, target, mid + 1, high);
}

int lastOccurrence(vector<int> &nums, int target, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    //* condition for element to be last occurrence
    if (mid < high && (nums[mid] == target && nums[mid] != nums[mid + 1]))
        return mid;

    //* if last element is equal to target, then it is the last occurring element
    if (nums[high] == target)
        return high;

    //* check if mid element is smaller or equal to target, then move to right part
    if (nums[mid] <= target)
        return lastOccurrence(nums, target, mid + 1, high);
    //* move to left part if nums[mid] greater than target
    else
        return lastOccurrence(nums, target, 0, mid - 1);
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
    int size = nums.size();

    //^ index1 = first occurrence,  index2 = last occurrence
    int index1 = firstOccurrence(nums, target, 0, size - 1);
    int index2 = lastOccurrence(nums, target, 0, size - 1);

    // storing the first and last index in the array
    ans.push_back(index1);
    ans.push_back(index2);

    return ans;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10, 11, 11, 11, 32};
    int target = 11;
    vector<int> ans = searchRange(nums, target);

    for (auto i : ans)
    {
        cout << i << " ";
    } //? end of for loop
    return EXIT_SUCCESS;
}