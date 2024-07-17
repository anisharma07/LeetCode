#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                return true;
            }

            // Check if the left half is sorted
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target < nums[mid])
                {
                    high = mid;
                    cout << high << endl;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // Otherwise, the right half must be sorted
            else
            {
                if (nums[mid] < target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 0, 1, 1, 1};
    int target = 0;
    cout << s.search(nums, target);

    return 0;
}