#include <bits/stdc++.h>
using namespace std;

//* Method 1: using a structure for start and end time
struct Interval
{
    int start, end;
};

void mergeIntervals(Interval arr[], int n)
{
    if (n <= 0)
        return;
    //*push first element of sorted array in the stack
    stack<Interval> st;
    st.push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        Interval top = st.top();

        //& if top elements end is less than the current element starting time, then there will be a new interval
        if (top.end < arr[i].start)
            st.push(arr[i]);

        //& if ending time of top is less than current el's ending time, then their will be a merge interval
        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            st.pop();
            st.push(top);
        }
    } //? end of for loop

    //& display all the intervals stored in the stack
    while (!st.empty())
    {
        Interval top = st.top();
        cout << top.start << " " << top.end << endl;
        st.pop();
    }

    return;
}

//*Method 2 --  using vector of vectors
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> mergeIntervals;
    //* if the vector is empty
    if (intervals.size() == 0)
        return mergeIntervals;

    //* sort the intervals on basis of starting time
    sort(intervals.begin(), intervals.end());

    //* taking the first interval and then will compare all next intervals with it
    vector<int> temp = intervals[0];

    for (auto itr : intervals)
    {
        //* if the current interval start time is less than the temp end time, then it will be merged
        if (itr[0] <= temp[1])
        {
            temp[1] = max(temp[1], itr[1]);
        }
        else
        {
            //* a new interval since there is no overlapping, so push the temp in answer and set temp as next pair
            //* in the vector
            mergeIntervals.push_back(temp);
            temp = itr;
        }
    }

    //* to push the last interval
    mergeIntervals.push_back(temp);
    return mergeIntervals;
}

int main(int argc, char *argv[])
{
    Interval arr[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = sizeof(arr) / sizeof(arr[0]);

    //* sort array in increasing start time
    sort(arr, arr + n, [](Interval a, Interval b)
         { return a.start < b.start; });

    mergeIntervals(arr, n);
    // for (auto i : arr)
    // {
    //     cout << i.start << " " << i.end << endl;
    // }

    return EXIT_SUCCESS;
}