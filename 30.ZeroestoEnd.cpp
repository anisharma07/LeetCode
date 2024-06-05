#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        for (int i = count; i < n; ++i)
        {
            if (nums[i] != 0)
            {
                nums[count] = nums[i];
                if (i != count)
                {
                    nums[i] = 0;
                }
                ++count;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}