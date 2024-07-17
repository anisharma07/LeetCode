#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> rightMax(n, 0), leftMax(n, 0);
        int r = INT_MIN, l = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            rightMax[n - i - 1] = max(height[n - i - 1], r);
            leftMax[i] = max(height[i], l);
            r = max(rightMax[n - i - 1], r);
            l = max(leftMax[i], l);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += min(leftMax[i], rightMax[i]) - height[i];
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(height);

    return 0;
}