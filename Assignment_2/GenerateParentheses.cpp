#include <bits/stdc++.h>
using namespace std;

//Print all combinations of balanced parentheses

void allParenthesesHelper(vector<char> &result, int n, int openBrackets, int closedBrackets, string str)
{
    // cout << " Hello ";

    if (closedBrackets == n)
    {
        result.push_back('{');
        result.push_back('}');
        cout << "{} ";
        return;
    }
    if (openBrackets > closedBrackets)
    {
        allParenthesesHelper(result, n, openBrackets, closedBrackets + 1, str + '}');
    }
    if (openBrackets < n)
    {
        allParenthesesHelper(result, n, openBrackets + 1, closedBrackets, str + '{');
    }
}

vector<char> allParentheses(int n)
{
    vector<char> result;
    // cout << " Hello ";

    if (n == 0)
    {
        return result;
    }
    if (n == 1)
    {
        result.push_back('{');
        result.push_back('}');
        return result;
    }
    allParenthesesHelper(result, n, 0, 0, "");
    return result;
}

int main()
{
    int n = 3;
    // cout << " Hello ";
    vector<char> arr = allParentheses(n);
    string res = "";
    for (int i = 0; i < arr.size(); i++)
    {
        res += arr[i];
    }
    cout << endl;
    cout << res;
    return 0;
}