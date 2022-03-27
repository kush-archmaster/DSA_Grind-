#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int size = height.size();
    int left = 0,
        right = size - 1,
        //& considering max product initially to be prod of first and last num
        area = INT_MIN;

    while (left < right)
    {
        area = max(area, min(height[left], height[right]) * (right - left));

        //& we will move the pointer which is comparatively smaller since we want greater area than now
        if (height[left] <= height[right])
            left++;
        else
            right--;
    }
    return area;
}

int main(int argc, char *argv[])
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;

    return EXIT_SUCCESS;
}