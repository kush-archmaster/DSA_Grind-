#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    int size = nums.size();

    if (size == 0)
        return ans;
    sort(nums.begin(), nums.end());

    for (int i = 1; i < size; i++)
    {
        //^ to avoid taking duplicate value of i
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        //* using two pointer approach
        int left = i + 1,
            right = size - 1,
            sum = 0 - nums[i];

        while (left < right)
        {
            //^ since the target sum is 0
            if ((nums[left] + nums[right]) == sum)
            {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[left]);
                temp.push_back(nums[right]);
                ans.push_back(temp);

                //^ ignore the duplicate values of left
                while (left < right && nums[left] == nums[left + 1])
                    left++;

                //^ ignore the duplicate values of right
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                //^ to start with next different value
                left++;
                right--;
            }
            //^ if sum less than 0
            else if ((nums[left] + nums[right]) < sum)
                left++;
            //^ else if sum greater than 0
            else
                right--;
        }

    } //? end of for loop
    return ans;
}

void display(vector<vector<int>> &ans)
{
    int ans_size = ans.size();
    for (int i = 0; i < ans_size; i++)
    {
        for (auto x : ans[i])
        {
            cout << x << " ";
        } //? end of nested for loop

        cout << endl;
    } //? end of for loop
}

int main(int argc, char *argv[])
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4, 6, -6};
    vector<vector<int>> ans;

    //& store the triplets with sum=target in the ans vector
    ans = threeSum(nums);

    //& display the triplets
    display(ans);
    return EXIT_SUCCESS;
}
