#include <bits/stdc++.h>
using namespace std;

//Find mejority Element in the array

int findMejorityElement(vector<int> &vec)
{
    int ms = vec[0];
    int curr_mej = vec[0];
    int freq = 1;

    // First we need to fine the freq which is occurring the maximum number of times
    for (int i = 1; i < vec.size(); i++)
    {
        if (freq == 0)
        {
            curr_mej = vec[i];
            ms = curr_mej;
            freq = 1;
        }
        if (vec[i] == curr_mej)
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    // Let's count the element which is occurred maximum number of times
    int mejorityElement = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == ms)
        {
            mejorityElement++;
        }
    }
    if (mejorityElement > vec.size() / 2)
    {
        return ms;
    }
    return -1;
}

int main()
{
    // vector<int> arr = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    vector<int> arr = {3, 3, 4, 2, 4, 4, 2, 4};

    // If there is not mejority Element, this function will return -1; else it will return the mejority element
    cout << findMejorityElement(arr);
    return 0;
}