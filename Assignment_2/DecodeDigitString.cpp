#include <bits/stdc++.h>
using namespace std;

vector<string> mp = {
    "",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
};

void decodeStringHelper(vector<string> &result, string digits, int index, string stringSoFar)
{
    if (index >= digits.size())
    {
        result.push_back(stringSoFar);
        return;
    }
    int idx = int(digits[index] - '0');
    // If this index is 0, we cannot map with any character
    if (idx == 0)
    {
        return;
    }
    decodeStringHelper(result, digits, index + 1, stringSoFar + mp[idx]);

    // Now, check for 2 digits together
    if (index + 1 >= digits.size())
    {
        return;
    }
    int idx2 = int(digits[index + 1] - '0');
    if (idx * 10 + idx2 <= 26)
    {
        decodeStringHelper(result, digits, index + 2, stringSoFar + mp[idx * 10 + idx2]);
    }
}

vector<string> decodeString(string digits)
{
    if (digits.empty())
    {
        return vector<string>{};
    }
    vector<string> result;
    decodeStringHelper(result, digits, 0, "");
    return result;
}

int main()
{
    string digits = "25034950";
    vector<string> result = decodeString(digits);
    for (auto x : result)
    {
        cout << x << " ";
    }
    return 0;
}