#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void subs(vector<int> &nums, vector<vector<int>> &finans, vector<int> &ans, int i, int n)
    {

        if (i >= n)
        {
            finans.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        subs(nums, finans, ans, i + 1, n);
        ans.pop_back();
        subs(nums, finans, ans, i + 1, n);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<vector<int>> finans;
        vector<int> ans;
        int n = nums.size();
        int i = 0;

        subs(nums, finans, ans, i, n);
        return finans;
    }
};

int main()
{

    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = s.subsets(nums);

    return 0;
}