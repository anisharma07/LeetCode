#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        k = n - k;
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++)
        {
            result[i] = nums[(k + i) % n];
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = result[i];
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(nums, 3);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}