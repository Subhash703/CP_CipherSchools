#include <bits/stdc++.h>
using namespace std;

//Find first and last positions of an element in a sorted array
/*
Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array. 

Input : arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125}    
        x = 5
Output : First Occurrence = 2
         Last Occurrence = 5

*/

int binarySearchFirst(vector<int> &v, int start, int end, int x) // Binary Search O(log(n))
{
    if (v[start] == x)
    {
        return start;
    }
    start++;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (v[mid] == x && v[mid - 1] != x)
        {
            return mid;
        }
        else if (v[mid] < x)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int binarySearchLast(vector<int> &v, int start, int end, int x) // Binary Search O(log(n))
{
    if (v[end] == x)
    {
        return end;
    }
    end--;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (v[mid] == x && v[mid + 1] != x)
        {
            return mid;
        }
        else if (v[mid] <= x)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
/*
    To solve this we are going to use modified binary search, we will write 2 binarysearch to find the first occurance and other to find the last occurrance of the element, if the element is not found we will return -1;
*/

int main()
{
    // vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    // vector<int> arr = {5, 5, 5, 5, 5, 5, 67, 123, 125};
    // vector<int> arr = {5, 5, 5, 5, 5, 5, 6, 7, 67, 100};
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 67, 100};
    int x = 5;
    int st = binarySearchFirst(arr, 0, arr.size() - 1, x);
    if (st == -1)
    {
        cout << "No element found!" << endl;
        return 0;
    }
    int ed = binarySearchLast(arr, st, arr.size() - 1, x);
    cout << "First Index : " << st << endl;
    cout << "Last Index : " << ed << endl;

    return 0;
}