#include <bits/stdc++.h>
using namespace std;

//Count Inversions in an array
/*
Inversion Count for an array indicates – how far (or close) the array is from being sorted.
*/

// The brute force technique is to use 2 for loops, with time complexity of O(N^2) and find the inversions
// where arr[i]>arr[j] => i<j
int countInversions(vector<int> &vec)
{
    int inversions = 0;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[i] > vec[j])
            {
                inversions++;
            }
        }
    }
    return inversions;
}

/*
    But that approach is not the correct way to solve this problem, we will use another approach with 
    Time : O(nlog(n))
    Space : O(n)

    {2, 4, 1, 3, 5, 10, 15, 11, 7}; => 7
    {1, 2, 3, 4, 5, 7,  10, 11, 15};
*/

int main()
{
    vector<int> arr = {2, 4, 1, 3, 5, 10, 15, 11, 7};
    // vector<int> arr = {2, 3, 4, 5, 6}; // Sorted , so inversions should be 0
    cout << "Total inversions : " << countInversions(arr) << endl;
    return 0;
}