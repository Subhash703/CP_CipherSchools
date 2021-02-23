#include <bits/stdc++.h>
using namespace std;

// Construct a value N, we have coins {s1,s2,s3,....sm} infin quantity
/*
    {1,2,3}
    4 = {1,1,1,1}, {1,1,2}, {1,3}, {2,2} 4 ways

    ***** N = 1 + T(N-1)
                            4
           1(3)               2(2)              3(1)
    1(2)   2(1)   3(0)       1   2   3       1   2   3
    0   1   2   3   4   5 (N)
0   1   0   0   0   0   0
1   1   1
2   1   0
3   1   0
(coins i have)

if(coin[i-1]<=N){

}
*/

int CoinChange(int sum, vector<int> coins)
{
    int coinCount = coins.size();
    vector<vector<int>> dp(sum + 1, vector<int>(coinCount, 0));
    for (int c = 0; c < coinCount; c++)
    {
        dp[0][c] = 1;
    }
    for (int s = 1; s <= sum; s++)
    {
        for (int c = 0; c < coinCount; c++)
        {
            if (s >= coins[c])
            {
                dp[s][c] += dp[s - coins[c]][c];
                //dp[4][3] += dp[4-coint[3]][3];
            }
            if (c >= 1)
            {
                dp[s][c] += dp[s][c - 1];
            }
        }
    }
    return 1;
}

int main()
{
    vector<int> coins = {1, 2, 3, 5};

    return 0;
}