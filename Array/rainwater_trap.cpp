#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int size = height.size(),
        area = 0;
    vector<int> maxL(size, -1),
        maxR(size, -1);

    //& calculate max left array
    maxL[0] = height[0];
    for (int i = 1; i < size; i++)
        maxL[i] = max(height[i], maxL[i - 1]);

    //& calculate max right array
    maxR[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--)
        maxR[i] = max(height[i], maxR[i + 1]);

    //& calculate total area
    for (int i = 1; i < size - 1; i++)
    {
        area += (min(maxL[i], maxR[i]) - height[i]);
    }
    return area;
}

int main(int argc, char *argv[])
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    //* total area that will trap rain
    cout << trap(height) << endl;
    return EXIT_SUCCESS;
}