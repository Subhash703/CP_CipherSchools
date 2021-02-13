#include <bits/stdc++.h>
using namespace std;

// Problem : Find a peak element
/*
Given an array of integers. Find a peak element in it. An array element is a peak if it is NOT smaller than its neighbours. For corner elements, we need to consider only one neighbour. 

So we have to think about 3 cases 
    peak element is on edges 
        arr[0]>arr[1]
        arr[n-1]>arr[n-2]
    in between 
        arr[i]>arr[i-1] && arr[i]>arr[i+1]

*/
int findPeakElement(vector<int> &vec)
{
    int n = vec.size();
    if (n == 0)
    {
        return -1;
    }
    if (n == 1)
    {
        return vec[0];
    }
    if (vec[0] > vec[1])
        return vec[0];
    if (vec[n - 1] > vec[n - 2])
        return vec[n - 1];
    for (int i = 1; i < n - 1; i++)
    {
        if (vec[i] > vec[i - 1] && vec[i] > vec[i + 1])
        {
            return vec[i];
        }
    }
    return -1;
}

int main()
{
    // vector<int> arr = {10, 15, 20, 10};
    vector<int> arr = {100, 90, 15, 2, 23, 10, 7};
    cout << "Peak Element is :" << endl;
    cout << findPeakElement(arr);
    return 0;
}