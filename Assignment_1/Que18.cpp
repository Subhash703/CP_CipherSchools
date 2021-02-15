#include <bits/stdc++.h>
using namespace std;

//Search an element in a sorted and rotated array
/*
    We will do it in O(log(n)) time, because array is sorted and we can find solution for sorted array in logn time
*/
int findPivotElement(vector<int> arr, int start, int end)
{
    if (end < start)
    {
        return -1;
    }
    if (end == start)
    {
        return start;
    }
    //5 6 7 8 9 1 2 3 4
    int mid = start + (end - start) / 2;
    if (mid < end && arr[mid] > arr[mid + 1])
    {
        return mid;
    }
    if (mid > start && arr[mid] < arr[mid - 1])
    {
        return mid - 1;
    }
    if (arr[start] >= arr[mid])
    {
        return findPivotElement(arr, start, mid - 1);
    }
    return findPivotElement(arr, mid + 1, end);
}

int binarySearch(vector<int> v, int start, int end, int key)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] == key)
        {
            return mid;
        }
        else if (v[mid] > key)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int findElementInRotatedArray(vector<int> v, int key)
{
    int n = v.size();
    int pivot = findPivotElement(v, 0, n - 1);

    // if there is no pivot means array is not rotated
    if (pivot == -1)
    {
        return binarySearch(v, 0, n - 1, key);
    }

    //
    if (v[pivot] == key)
    {
        return pivot;
    }
    if (v[pivot] < key)
    {
        return binarySearch(v, 0, pivot - 1, key);
    }

    return binarySearch(v, pivot + 1, n - 1, key);
}

int main()
{
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 7;
    cout << "Element was found at : " << findElementInRotatedArray(arr, key) << endl;
    return 0;
}