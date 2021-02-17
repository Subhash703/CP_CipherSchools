#include <bits/stdc++.h>
using namespace std;

vector<string> keypads = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// Recursive function
void generatePossibleCombinationsHelper(vector<string> &result, string digits, int index, string stringSoFar)
{
    if (index == digits.size())
    {
        result.push_back(stringSoFar);
        // cout << stringSoFar << " ";
        return;
    }
    string possibleMoves = keypads[digits[index] - '0']; // => keypads['2'-'0'] => keypads[2]

    // Now go through this possible moves and make strings
    for (int i = 0; i < possibleMoves.size(); i++)
    {
        // Include current character
        stringSoFar.push_back(possibleMoves[i]);
        generatePossibleCombinationsHelper(result, digits, index + 1, stringSoFar);
        // Do not include current character
        stringSoFar.pop_back();
    }
}

vector<string> generatePossibleCombinations(string digits)
{
    if (digits.empty())
    {
        return vector<string>{};
    }
    vector<string> result;
    generatePossibleCombinationsHelper(result, digits, 0, "");
    return result;
}

int main()
{
    string digits = "234";
    // cout << "Value : " << keypads[digits[2] - '0'];
    vector<string> result = generatePossibleCombinations(digits);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}