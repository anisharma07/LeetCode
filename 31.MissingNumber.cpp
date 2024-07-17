#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> hash(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            hash[nums[i]] += 1;
        }
        for (int i = 0; i <= n; i++)
        {
            if (hash[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 0, 1};
    cout << s.missingNumber(nums) << endl;

    return 0;
}