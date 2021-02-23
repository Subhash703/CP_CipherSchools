#include <bits/stdc++.h>
using namespace std;

void siftDown(int a[], int k, int n)
{

    while (2 * k <= n)
    {
        int j = 2 * k;
        if (j < n && a[j + 1] > a[j])
        {
            j++;
        }
        if (a[k] > a[j])
        {
            break;
        }
        swap(a[k], a[j]);
        k = j;
    }
}

int main()
{
    int a[6] = {100, 5, 4, 3, 2, 1};
    int n = 5;
    for (int k = n / 2; k >= 1; k--)
    {
        siftDown(a, k, n);
    }
    int t = n;
    while (n > 1)
    {
        swap(a[1], a[n--]);
        siftDown(a, 1, n);
    }
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}