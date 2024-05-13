#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = s.removeDuplicates(nums);
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}