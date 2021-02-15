#include <bits/stdc++.h>
using namespace std;

//Printing matrix in spiral form
void printMatrixInSpiralForm(vector<vector<int>> &matrix)
{
    int rs = 0, re = matrix.size() - 1, cs = 0, ce = matrix[0].size() - 1;
    cout << rs << " " << re << " " << cs << " " << ce << endl;

    while (rs <= re && cs <= ce)
    {
        for (int i = cs; i <= ce; i++)
        {
            cout << matrix[rs][i] << " ";
        }
        rs++;
        for (int i = rs; i <= re; i++)
        {
            cout << matrix[i][ce] << " ";
        }
        ce--;

        if (rs < re)
        {
            for (int i = ce; i >= cs; i--)
            {
                cout << matrix[re][i] << " ";
            }
            re--;
        }
        if (cs < ce && rs < re)
        {
            for (int i = re; i >= rs; i--)
            {
                cout << matrix[i][cs] << " ";
            }
            cs++;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5, 6},
                                  {7, 8, 9, 10, 11, 12},
                                  {13, 14, 15, 16, 17, 18}};
    printMatrixInSpiralForm(matrix);
    return 0;
}