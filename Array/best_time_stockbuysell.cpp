#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int profit = 0,
        size = prices.size();

    // here we can buy at different dates so, this approach can be used, whenever we get a profit, we add it to our profit buffer
    for (int i = 1; i < size; i++)
    {
        if (prices[i] > prices[i - 1])
            profit += (prices[i] - prices[i - 1]);
    }
    return profit;
}

int main(int argc, char *argv[])
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Profit: " << maxProfit(prices);
    return EXIT_SUCCESS;
}