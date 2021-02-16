#include <bits/stdc++.h>
using namespace std;

// Maximum water trapped between containers

int trapRainWater(vector<int> &arr)
{
    cout << "Running!" << endl;
    int size = arr.size();
    vector<int> r_max(size);
    r_max[size - 1] = arr[size - 1];

    for (int j = size - 2; j >= 0; j--)
    {
        r_max[j] = max(arr[j], r_max[j + 1]);
    }
    int l_max = arr[0];
    int trappedWater = 0;
    for (int i = 0; i < size; i++)
    {
        l_max = max(arr[i], l_max);
        trappedWater += (min(r_max[i], l_max) - arr[i]);
    }

    return trappedWater;
}

int main()
{
    vector<int> arr = {9, 1, 0, 2, 6, 0, 1, 0, 8, 1, 2, 1};
    cout << "Trapped Water : " << trapRainWater(arr);
    return 0;
}
