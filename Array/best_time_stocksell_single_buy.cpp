#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int size = prices.size();
    int min_value_to_buy = 0, max_profit = 0;
    bool flag = false;

    //^ starting the loop from first element
    for (int i = 1; i < size; i++)
    {
        //* for first case when we dont have a min value set
        if (flag == false)
        {
            //* maintaining min value encountered till now for single buy option
            min_value_to_buy = min(prices[i], prices[i - 1]);
            flag = true;
        }
        else
            min_value_to_buy = min(min_value_to_buy, prices[i]);

        //* caclulating max profit from the single buy date
        max_profit = max(max_profit, prices[i] - min_value_to_buy);
    }

    return max_profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int ans = maxProfit(prices);

    cout << ans << endl;
    return EXIT_SUCCESS;
}