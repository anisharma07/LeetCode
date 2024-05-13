#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int maxArea = 0;
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            int distance = right - left;
            int minHeight = min(height[left], height[right]);
            int area = distance * minHeight;
            maxArea = max(maxArea, area);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxArea;
    }
};

int main()
{
    Solution s;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s.maxArea(height);

    return 0;
}
