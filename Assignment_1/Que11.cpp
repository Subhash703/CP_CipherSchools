#include <bits/stdc++.h>
using namespace std;
//Stock Buy Sell to Maximize Profit

int maximumStockPriceOnceSell(vector<int> &stockPrices)
{
    int profit = 0;
    int minStockPrice = stockPrices[0];
    for (int i = 1; i < stockPrices.size(); i++)
    {
        if (minStockPrice <= stockPrices[i])
        {
            int tempProfit = stockPrices[i] - minStockPrice;
            profit = max(profit, tempProfit); // 80 + 160  + 210 + 495 + 655
        }
        else
        {
            minStockPrice = stockPrices[i];
        }
    }
    return profit;
}

int maximumProfitInMultipleSell(vector<int> &stockPrices)
{
    int profit = 0;
    int minStockPrice = stockPrices[0];
    cout << "Baught stock at :" << minStockPrice << " & ";
    for (int i = 1; i < stockPrices.size(); i++)
    {
        while (i < stockPrices.size() && stockPrices[i - 1] <= stockPrices[i])
        {
            i++;
            continue;
        }
        cout << "I'm selling the stock : " << stockPrices[i - 1] << endl;
        profit += stockPrices[i - 1] - minStockPrice;
        if (i < stockPrices.size())
        {
            minStockPrice = stockPrices[i];
            cout << "Baught stock at :" << minStockPrice << " & ";
        }
    }
    return profit;
}

int main()
{
    // vector<int> stockPrices = {100, 180, 260, 310, 40, 535, 695};
    vector<int> stockPrices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit : " << maximumStockPriceOnceSell(stockPrices) << endl;

    // When we can buy and sell stocks more than once
    cout << "Maximum profit :" << maximumProfitInMultipleSell(stockPrices) << endl;
    return 0;
}