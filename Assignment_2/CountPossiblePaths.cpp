#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
/*
Input :  m = 2, n = 2;
Output : 2
    (0,0) -> (0,1) 
    (1,0) -> (1,1)
*/
void findAllPossiblePathsHelper(int &countPaths, int m, int n, int x, int y)
{
    if (x == m && y == n)
    {
        cout << "H ";
        countPaths++;
        return;
    }
    if (x > n && y > m)
    {
        return;
    }
    findAllPossiblePathsHelper(countPaths, m, n, x + 1, y);
    findAllPossiblePathsHelper(countPaths, m, n, x, y + 1);
}

int findAllPossiblePaths(int m, int n)
{
    if (m == 0 && n == 0)
    {
        return 1;
    }
    int countPaths = 0;
    findAllPossiblePathsHelper(countPaths, m, n, 0, 0);
    return countPaths;
}

int main()
{
    int m = 2, n = 2;
    cout << findAllPossiblePaths(m, n) << endl;
    return 0;
}