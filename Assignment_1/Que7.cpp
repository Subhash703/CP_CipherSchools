#include <bits/stdc++.h>
using namespace std;

//Alternative Sorting
/*
    Given an array of integers, print the array in such a way that the first element is first maximum and second element is first minimum and so on.
    Input : arr[] = {7, 1, 2, 3, 4, 5, 6}
    Output : 7 1 6 2 5 3 4

*/

void alternativeSorting(vector<int> &vec)
{
    sort(vec.begin(), vec.end());
    // 1 2 3 4 5 6 7
    // 7 1 6 2 5 3 4
    // Now we can print ulternatively
    int start = 0, end = vec.size() - 1;
    while (start <= end)
    {
        cout << vec[end--] << " " << vec[start++] << " ";
    }
}
/*

*/

int main()
{
    // vector<int> arr = {7, 1, 2, 3, 4, 5, 6, 8, 9, 20};
    vector<int> arr = {1, 6, 9, 4, 3, 7, 8, 2};
    alternativeSorting(arr);
    return 0;
}