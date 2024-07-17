#include <bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Solution
{
public:
    void getSubsets(int index, int k, int target, vector<int> &ds, vector<int> &numbers, vector<vector<int>> &result)
    {
        if (target < 0)
            return;
        if (k <= 0)
        {
            if (target == 0)
                result.push_back(ds);
            return;
        }
        for (int i = index; i <= 9; i++)
        {
            if ((k == 1 && i <= target) || i < target)
            {

                if (numbers[i - 1] == 0)
                {
                    // cout << i << " ";
                    ds.push_back(i);
                    numbers[i - 1] = 1;
                    getSubsets(i + 1, k - 1, target - i, ds, numbers, result);
                    numbers[i - 1] = 0;
                    ds.pop_back();
                }
            }
            else
            {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> numbers(9, 0);
        vector<int> ds;
        vector<vector<int>> result;
        getSubsets(1, k, n, ds, numbers, result);
        return result;
    }
};

int main()
{
    init_code();
    Solution s;
    vector<vector<int>> result = s.combinationSum3(3, 7);
    for (auto x : result)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}