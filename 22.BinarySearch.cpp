#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size();
        if (target < nums[0])
            return 0;
        if (target > nums[r - 1])
            return r;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << s.searchInsert(nums, target) << endl;

    return 0;
}