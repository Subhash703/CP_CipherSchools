#include <bits/stdc++.h>
using namespace std;

//Segregate 0s and 1s in an array
/*
You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array. Traverse array only once.
    Input array   =  [0, 1, 0, 1, 0, 0, 1, 1, 1, 0] 
    Output array =  [0, 0, 0, 0, 0, 1, 1, 1, 1, 1] 
*/

void segregateArray(vector<int> &vec)
{
    int n = vec.size();
    int start = 0, end = n - 1;
    while (start < end)
    {
        while (vec[start] == 0)
        {
            start++;
        }
        while (vec[end] == 1)
        {
            end--;
        }
        if (start < end)
        {
            swap(vec[start], vec[end]);
        }
    }
}
/*
    -> The brute force technique is to count the 0s and 1s and then fill the 0s and 1s => O(n) 
    -> I'm using the 2 pointer approach which is the best way to solve this in O(n) time and O(1) space complexity
    
*/

int main()
{
    vector<int> arr = {0, 1, 0, 1, 0, 0, 1, 1, 0, 1};
    segregateArray(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}