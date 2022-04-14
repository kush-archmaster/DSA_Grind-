#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    //& considering nums1 length smaller than nums2 length
    if (nums2.size() < nums1.size())
        return findMedianSortedArrays(nums2, nums1);

    int begin1 = 0, end1 = nums1.size(); //& they are marked for smaller array (nums1) in this case
    while (begin1 <= end1)
    {
        int itr1 = (begin1 + end1) / 2;                          //& partition at nums1
        int itr2 = (nums1.size() + nums2.size() + 1) / 2 - itr1; //& partition at nums2

        //& marking min1,max1,min2,max2  --> (min1, min2 are in the right section || max1, max2 are in the left section)
        int min1 = (itr1 == nums1.size()) ? INT_MAX : nums1[itr1];
        int max1 = (itr1 == 0) ? INT_MIN : nums1[itr1 - 1];

        int min2 = (itr2 == nums2.size()) ? INT_MAX : nums2[itr2];
        int max2 = (itr2 == 0) ? INT_MIN : nums2[itr2 - 1];

        //& ideal condition when partitions made are such that entire left part is smaller than right part
        if ((max1 <= min2) && (max2 <= min1))
        {
            //& if number of elements in total are even
            if ((nums1.size() + nums2.size()) % 2 == 0)
                return (max(max1, max2) + min(min1, min2)) / 2.0;
            else
                return (max(max1, max2));
        }
        //& if left section has a greater element then shift the partition by one towards left  -->binary search (we will reduce the array to [0 - itr1-1])
        else if (max1 > min2)
            end1 = itr1 - 1;
        else
            begin1 = itr1 + 1;
    }

    return 0.0;
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1, 3},
                nums2 = {3, 4};

    cout << "Median : " << findMedianSortedArrays(nums1, nums2) << endl;
    return EXIT_SUCCESS;
}