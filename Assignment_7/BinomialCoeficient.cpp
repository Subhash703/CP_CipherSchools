// nCr ?
#include <bits/stdc++.h>
using namespace std;

/* nCr = n!/(n-r)!r! = (n-1)Cr + (n-1)C(r-1)

    0   1   2   3   4   5   6   <= n

0   0   1   1   1   1   1   1
1   0   1   2   3   4   5   6       
2   0       1   
3   0           1
^
||
r
*/

long BinomialCoffecient(long N, long R)
{
    vector<vector<long>> dp;
    for (long i = 0; i <= R; i++)
    {
        for (long j = 0; j <= min(i, R); j++)
        {
            if (i == 0 || j == 0)
            {
                // nC0 || 0C0
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
    }
}
int main()
{

    return 0;
}