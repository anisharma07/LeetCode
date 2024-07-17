#include<bits/stdc++.h>
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int el = nums[i], first = i, second;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] == el)
                {
                    second = j;
                    if (second - first <= k)
                        return true;
                    else
                    {
                        first = second;
                    }
                }
            }
        }
        return false;
    }
};

int main(){
init_code();

Solution s;
vector<int> nums = {1, 2, 3, 1, 2, 3};
int k = 2;
cout << s.containsNearbyDuplicate(nums, k);


return 0;
}