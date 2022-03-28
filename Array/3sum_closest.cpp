#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int size = nums.size(),
        minimum = INT_MAX,
        total = 0; // minimum sum possible

    //& if array is empty to minimum sum = 0
    if (size == 0)
        return total;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < size - 2; i++)
    {
        //& to skip the duplicate value of i
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        //* Two pointer approach -- only works if the array is sorted
        int left = i + 1,
            right = size - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (minimum > abs(target - sum))
            {
                total = sum;
                minimum = abs(target - sum);
            }
            //& if sum equals target then return sum as it is closest value possible
            if (sum == target)
                return sum;
            else if (sum < target)
                left++;
            else
                right--;
        }
    }

    return total;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    //* calling the utility function to get us the answer
    int ans = threeSumClosest(nums, target);

    cout << ans << endl;
    return EXIT_SUCCESS;
}