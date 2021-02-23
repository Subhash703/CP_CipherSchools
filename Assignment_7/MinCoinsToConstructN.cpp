#include <bits/stdc++.h>
using namespace std;

int minCoinstToMakeN(int N, vector<int> &coins)
{
    // (1.......m) = min(1st + c(v-c[i]))
    // we first find how much min nodes required to make 0 -> 1 -> 2 -> 3
    /*
        0   1   2   3   4   5
    0   0
    1
    2
    3
    4
    5

    */
    if (N == 0)
        return 0;
    int M = coins.size();
    int minCoins = INT_MAX;
    vector<int> dp(N + 1, INT_MAX);
    dp[0] = 0;
    for (int n = 1; n <= N; n++)
    {
        for (int i = 0; i < M; i++)
        {
            // AGAR current coin n se chhota h
            if (coins[i] <= n)
            {
                if (n - coins[i] == INT_MAX)
                    continue;
                dp[i] = min(dp[n], 1 + dp[n - coins[i]]);
            }
        }
    }

    if (dp[N] == INT_MAX)
        return -1;
    else
        return dp[N];
    return 0;
}

int main()
{
    // Find minimum no of coins required to construct N
    int N = 11;
    vector<int> coins = {9, 6, 5, 1};
    minCoinstToMakeN(N, coins);
    return 0;
}