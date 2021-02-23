#include <bits/stdc++.h>
using namespace std;

/*
            10
          /    \
        15      5   => MaxHeap => Hipify
      /    \
    4       20

*/
void maxHipify(vector<int> &arr, int n, int i)
{
    // if (2 * i + 2 > n)
    // {
    //     return;
    // }
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    // cout << largest << endl;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxHipify(arr, n, largest);
    }
}

/*
largest = 1, left = 3, right =4;
arr[left] = 4, arr[right]=20, arr[largest]=15
largest = right=4;

*/
void BuildMaxHeap(vector<int> &arr, int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxHipify(arr, n, i);
    }
}

void heapSort(vector<int> &arr, int n)
{
    BuildMaxHeap(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        maxHipify(arr, i, 0);
    }
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int n = arr.size();
    // Build a maxHeap first
    BuildMaxHeap(arr, n);

    // Repeatedly swap root with last node, reduce heap size by one and heapify again
    heapSort(arr, n);

    //Print array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}