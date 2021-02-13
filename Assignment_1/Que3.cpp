#include <bits/stdc++.h>
using namespace std;

//Search in a row wise and column wise sorted matrix
/*
    mat[4][4] = { {10, 20, 30, 40},
                  {15, 25, 35, 45},
                  {27, 29, 37, 48},
                  {32, 33, 39, 50}};
*/
int binarySearch(vector<int> v, int start, int end, int x) // Binary Search O(log(n))
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (v[mid] == x)
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

pair<int, int> findElementInSortedMatrix(vector<vector<int>> &vec, int ele)
{
    // Bruteforce is to put 2 for loops and find the element in the matrix,
    // It's not efficient to find that because it will take : O(N*M) space
    //Because the array is sorted, we can take benefit of it and apply binary search on some places
    pair<int, int> result;
    for (int col = 0; col < vec.size(); col++)
    {
        if (vec[col][0] == ele)
        {
            result.first = col;
            result.second = 0;
            return result;
        }
        if (vec[col][0] > ele)
        {
            int index = binarySearch(vec[col - 1], 0, vec[0].size() - 1, ele);
            if (index == -1)
            {
                result.first = -1;
                result.second = -1;
                return result;
            }
            else
            {
                result.first = col - 1;
                result.second = index;
            }
        }
        else if (col == vec.size() - 1)
        {
            int index = binarySearch(vec[col], 0, vec[0].size() - 1, ele);
            if (index == -1)
            {
                result.first = -1;
                result.second = -1;
                return result;
            }
            else
            {
                result.first = col - 1;
                result.second = index;
            }
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> arr = {{10, 20, 30, 40},
                               {15, 25, 35, 45},
                               {27, 29, 37, 48},
                               {32, 33, 39, 50}};

    pair<int, int> res = findElementInSortedMatrix(arr, 50);
    cout << "(" << res.first << "," << res.second << ")";
    return 0;
}