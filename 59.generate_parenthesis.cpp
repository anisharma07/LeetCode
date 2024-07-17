#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

class Solution
{
public:
    void backtrack(vector<string> &result, string str, int open, int close, int n)
    {
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;

        backtrack(result, "", 0, 0, n);
        return result;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Solution s;
    vector<string> res = s.generateParenthesis(6);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}