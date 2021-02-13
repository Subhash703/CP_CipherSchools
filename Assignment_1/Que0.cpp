#include <bits/stdc++.h>

using namespace std;

// Check if two people starting from different points ever meet
/*
Input  : x1 = 5, v1 = 8, x2 = 4, v2 = 7
Output : No
Explanation: The first person is starting ahead of the second one.
and his speed is also greater than the second one, so they will never meet.

*/
string WillPersonsMeet(int x1, int v1, int x2, int v2)
{
    if (x1 == x2)
    {
        return "Yes!";
    }
    if (x1 < x2 && v1 <= v2)
    {
        return "No!";
    }
    if (x2 < x1 && v2 <= v1)
    {
        return "No!";
    }

    // We check the relative speed of the persons, if that is perfect factor of the differences of the positions
    int rel_speed = abs(v1 - v2);
    //2, 2 | 1 1 => 1             2 => No

    if (x1 < x2)
    {
        swap(x1, x2);
        swap(v1, v2);
    }
    if ((x1 - x2) % rel_speed == 0)
    {
        return "Yes";
    }
    return "No!";
}

int main()
{
    int x1, v1, x2, v2;
    cout << "Enter the starting point and velocity of 1st person : ";
    cin >> x1 >> v1;

    cout << "Enter the starting point and velocity of 2nd person : ";
    cin >> x2 >> v2;

    cout << WillPersonsMeet(x1, v1, x2, v2);

    return 0;
}