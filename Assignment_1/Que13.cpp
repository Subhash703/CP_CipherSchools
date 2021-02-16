#include <bits/stdc++.h>
using namespace std;

//Kth smallest element in a row-wise and column-wise sorted 2D array
/*
Input:k = 3  
array =
        10, 20, 30, 40
        15, 25, 35, 45
        24, 29, 37, 48
        32, 33, 39, 50 
Output: 20

*/
int kthMinimumElement(vector<vector<int>> &matrix, int k)
{
    int cr = 0, cc = 0, i = 0, j = 1;
    int m = matrix.size(), n = matrix[0].size();
    int count = 0;
    while (cr < matrix.size() && cc < matrix[0].size())
    {

        if (matrix[i][cc] < matrix[cr][j])
        {
            count++;
            cout << "count : " << count << " : " << matrix[i][cc] << endl;
            if (count == k)
            {
                return matrix[i][cc];
            }
            i++;
        }
        else
        {
            count++;
            cout << "count : " << count << " : " << matrix[cr][j] << endl;
            if (count == k)
            {
                return matrix[cr][j];
            }
            j++;
        }
        if (i > m)
        {
            cc++;
            i = cr;
        }
        if (j > n)
        {
            cr++;
            j = cr;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{10, 20, 30, 40},
                                  {15, 25, 35, 45},
                                  {24, 29, 37, 48},
                                  {32, 33, 39, 50}};
    int k = 6;
    cout << kthMinimumElement(matrix, k);
    return 0;
}