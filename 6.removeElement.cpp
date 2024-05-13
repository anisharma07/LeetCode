#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        int n = nums.size();
        for (int j = 0; j < n; j++)
        {

            while (nums[j] == val)
            {
                j++;
            }
            nums[i++] = nums[j];
        }
        return i - 1;
    }
};

// class Solution
// { // most efficient
// public:
//     int removeElement(vector<int> &nums, int val)
//     {
//         nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
//         return nums.size();
//     }
// };

// class Solution { // most memory efficient
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int counter = nums.size();
//         for(int i=0; i < nums.size(); i++) {
//             if(nums[i] == val) {
//                 counter--;
//                 vector<int>::iterator it;
//                 it = nums.begin() + i;
//                 nums.erase(it);
//                 i--;
//             }
//         }
//         return counter;
//     }
// };

int main()
{

    Solution s;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int k = s.removeElement(nums, val);
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}