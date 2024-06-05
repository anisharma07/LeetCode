#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <iterator>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <bitset>
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <forward_list>
#include <array>
#include <tuple>
#include <initializer_list>

using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }

        int targetIndex = 1, ans = 1;

        while (targetIndex < n)
        {
            int currSum = 0;
            int i = 0;
            int curr = targetIndex + 1;

            for (int j = 0; j <= targetIndex; j++)
            {
                currSum += nums[j];
                cout << currSum << " ";
            }
            cout << endl;

            while ((curr * nums[targetIndex]) - currSum > k)
            {
                cout << currSum << " cuuuuuur";
                // cout << currSum << curr << nums[targetIndex];
                currSum -= nums[i];
                curr--;
                i++;
            }
            if (ans < curr)
            {
                ans = curr;
            }
            targetIndex++;
        };
        return ans;
    }
};

int main()
{

    Solution s;
    vector<int> nums = {3, 9, 6};
    cout << s.maxFrequency(nums, 2) << endl;

    return 0;
}