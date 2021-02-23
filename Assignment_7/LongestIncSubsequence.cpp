#include <bits/stdc++.h>
using namespace std;

/*
    10 | 22 9 33 21 50 31 60 80
    1  | 1  1  1  1  1  1  1  1  -> initial lis
    ----------------------------
    1    2  1  3  2  4  3
    element
        small <=curr_elemet
        prev_count + 1 > curr_count => update
*/
int longestIncreasingSubsequence(vector<int> nums)
{
    vector<int> lis(nums.size(), 1);
    int maxLis = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            // jth < ith
            if (nums[j] < nums[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
            maxLis = max(maxLis, lis[i]);
        }
    }
    return maxLis;
}
int main()
{
    vector<int> nums = {10, 22, 9, 33, 21, 50,
                        31,
                        60,
                        80};
}