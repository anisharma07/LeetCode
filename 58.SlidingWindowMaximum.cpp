#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int size = nums.size();

        deque<pair<int, int>> slidQueue;

        vector<int> res;
        for (int i = 0; i < k - 1; i++)
        {
            while (!slidQueue.empty() && slidQueue.front().first <= nums[i])
                slidQueue.pop_front();

            slidQueue.push_front({nums[i], i});
        }
        for (int i = k - 1; i < size; i++)
        {
            while (!slidQueue.empty() && slidQueue.front().first <= nums[i])
                slidQueue.pop_front();

            slidQueue.push_front({nums[i], i});

            while (slidQueue.back().second <= i - k)
                slidQueue.pop_back();
            if (i >= k - 1)
                res.push_back(slidQueue.back().first);
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = s.maxSlidingWindow(nums, k);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}