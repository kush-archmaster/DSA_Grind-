#include <bits/stdc++.h>
using namespace std;

//*    Method1:
//*        using hashmap , Tc-> O(n) Sc->O(n)

// bool containsDuplicate(vector<int>& nums) {
// using extra space --> hashmap
//         int size = nums.size();
//         map<int,int> mp;

// storing in the hashmap
//         for(int i=0; i<size; i++)
//             mp[nums[i]]++;

//         for(auto i:mp)
//         {
// checking if any element has count more than 1, if so then return true
//             if(i.second > 1)
//                 return true;
//         }
//         return false;
//     }

//*    Method2:
//*        when array is mutable, using index of elements and changing it to negative when encoutered.
//*        If a number is encountered twice (it is already negative)  --> thus it is the number which is duplicate

//*    Method3:
//*        when array is immutable, using floyd detection algo of linked lists in this, Tc--> O(n)  Sc-->O(1)  (bit tricky)
//* Solved in this part
int findDuplicates(vector<int> &nums)
{
    //& initialising slow and fast pointers as first(head) element
    int slow_ptr = nums[0],
        fast_ptr = nums[0];

    //& moving slow ptr by 1 position and fast ptr by 2
    do
    {
        slow_ptr = nums[slow_ptr];
        fast_ptr = nums[nums[fast_ptr]];
    } while (slow_ptr != fast_ptr);

    slow_ptr = nums[0];

    //& while slow pointer is equal to fast pointer
    while (slow_ptr != fast_ptr)
    {
        slow_ptr = nums[slow_ptr];
        fast_ptr = nums[fast_ptr];
    }
    return slow_ptr;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3, 3, 4, 5};
    cout << findDuplicates(nums) << endl;
    return EXIT_SUCCESS;
}