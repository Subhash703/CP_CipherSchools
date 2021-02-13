#include <bits/stdc++.h>
using namespace std;

//Sort an array having 0s , 1s and 2s
/*
Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that sorts the given array. The functions should put all 0s first, then all 1s and all 2s in last.
Input: {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}
Output: {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}
*/

void SortArray(vector<int> &vec)
{
    int zp = 0, op = 0, tp = vec.size() - 1;
    while (op <= tp)
    {
        switch (vec[op])
        {
        case 0:
            swap(vec[zp], vec[op]);
            zp++;
            op++;
            break;
        case 1:
            op++;
            break;
        case 2:
            swap(vec[op], vec[tp]);
            tp--;
            break;
        default:
            break;
        }
    }
}
/*
    -> The brute force technique is to count the 0s,1s  and 2s and then fill the 0s and 1s => O(n) 
    -> I'm using the 3 pointer approach which is the best way to solve this in O(n) time and O(1) space complexity
    
*/

int main()
{
    vector<int> arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    SortArray(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}