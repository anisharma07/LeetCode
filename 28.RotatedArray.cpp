#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int x = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                x = i + 1;
                for (int j = 0; j < n - 1; j++)
                {
                    int m = (j + x) % n;
                    if (nums[m] > nums[(m + 1) % n])
                    {
                        return false;
                    }
                }
                break;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 1, 3, 4};
    cout << s.check(nums) << endl;

    return 0;
}