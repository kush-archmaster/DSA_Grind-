#include <bits/stdc++.h>
using namespace std;

// * using kadanes algorithm
int maxSubArray(vector<int> &nums)
{
    //? assuming the first element has only itself in subarray ending with it.
    int maxsub = nums[0],
        sum = nums[0],
        n = nums.size();

    if (n == 1)
        return sum;

    for (int i = 1; i < n; i++)
    {
        //? either it can be a part of a subarray ending with it, or it may be start of a new subarray
        maxsub = max(maxsub + nums[i], nums[i]);
        sum = max(sum, maxsub);
    }
    return sum;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = maxSubArray(nums);
    cout << ans << endl;
    return EXIT_SUCCESS;
}