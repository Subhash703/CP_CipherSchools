#include <bits/stdc++.h>

using namespace std;

/*
    lengt => 1  2   3   4   5   6   7   8
    price => 1  5   8   9   10  17  17  20

0length rod price = 0;
l = 1 : only 1 way : profit = 1;
l = 2 : 1,1 : p(1)+p(1) = 2
        0,2 : p(0)+p(2) = 5
    3 : 1,2 : 1 + p(2) = 6
        0,3 : 0 + p(3) =>
*/
int RodCutting(vector<int> prices, int l)
{
    int N = prices.size();
    vector<int> dp(l, 0);

    for (int i = 0; i < l; i++)
    {
        dp[l] = prices[i]; //Nhi break kr rha to
        for (int j = 0; j < i; j++)
        {
            dp[i] = max(dp[i], dp[j] + dp[i - j - 1]);
            //dp[5] = max(dp[5],dp[1]+dp[3])
        }
    }
    return dp[l - 1];
}
int main()
{

    return 0;
}