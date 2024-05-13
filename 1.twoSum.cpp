#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int key = i;
            int j = i + 1;
            while (j < n)
            {
                if (nums[i] + nums[j] == target)
                {
                    vector<int> passed = {i, j};
                    return passed;
                }
                j++;
            }
        }
        vector<int> failedVector = {0};
        return failedVector;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = s.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}