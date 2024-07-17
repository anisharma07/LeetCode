#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        int x = nums[0];
        for (int i = 1; i < n; i++)
        {
            x ^= nums[i];
        }
        return x;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << s.singleNumber(nums) << endl;

    return 0;
}