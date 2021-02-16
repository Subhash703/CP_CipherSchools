#include <bits/stdc++.h>
using namespace std;

//Minimum Number of Platforms Required for a Railway/Bus Station

int minimumPlatformsRequired(vector<int> &arr, vector<int> &dep)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    //arr => {900 940 950 1100 1500 1800}
    //dep => {910 1120 1130 1200 1900 2000}
    int platFormCount = 1;
    int result = 1;
    int j = 0, i = 1;
    while (i < arr.size() && j < dep.size())
    {
        if (arr[i] <= dep[j])
        {
            platFormCount++;
            i++;
        }
        else
        {
            platFormCount--;
            j++;
        }
        result = max(result, platFormCount);
    }
    return result;
}

int main()
{
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "Minimum Platforms required : " << minimumPlatformsRequired(arr, dep);
    return 0;
}