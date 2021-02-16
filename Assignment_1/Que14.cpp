#include <bits/stdc++.h>
using namespace std;

///Largest Sum Contiguous Subarray
int largestSubArraySum(vector<int> &arr)
{
    int n = arr.size();
    int maxSoFar = arr[0];
    int result = 0;
    for (int i = 1; i < n; i++)
    {
        maxSoFar = max(arr[i], arr[i] + maxSoFar);
        cout << maxSoFar << " ";
        result = max(result, maxSoFar);
    }
    cout << endl;
    return result;
}

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    // vector<int> arr = {2, 1, 4, 7, 3, 6};
    cout << "Maximum Subarray Sum : " << largestSubArraySum(arr) << endl;
    return 0;
}