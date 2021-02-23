#include <iostream>
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

//k = 2, j = 4

int main()
{
    // your code goes here
    int a[6] = {100, 5, 50, 4, 20, -1};
    int n = 5;
    //a[0] = 100; ==> ignored
    //a[1] = 50, a[2] = 20, a[3] = 4, a[4] = 5, a[5] = -1;
    for (int k = n / 2; k >= 1; k--)
    {
        siftDown(a, k, n);
    }
    int t = n;
    cout << "Max Heap contents: " << endl;
    for (int i = 1; i <= t; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    while (n > 1)
    {
        swap(a[1], a[n--]);
        siftDown(a, 1, n);
    }
    for (int i = 1; i <= t; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}