#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <deque>
using namespace std;

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        //         long long ans=0;
        //    for(int i=1; i<=n;i++){
        //     for(int j=0; j<=n-i; j++){
        //         int minEle=INT_MAX;
        //         int maxEle=INT_MIN;
        //         for(int k=j; k<j+i; k++){
        // minEle=min(minEle, nums[k]);
        // maxEle=max(maxEle, nums[k]);

        //         }
        //         ans+=maxEle-minEle;
        //     }
        //    }
        //    ans=ans%(1000000007);
        //   return int(ans);

        // Using DEQUE
        // long long ans=0;
        // for(int i =0; i<n; i++){
        //     deque<int> maxDeque, minDeque;
        //     for(int j=i; j<n; j++){
        // while(!maxDeque.empty() && nums[maxDeque.back()]<=nums[j]) maxDeque.pop_back();
        // while(!minDeque.empty() && nums[minDeque.back()]>=nums[j]) minDeque.pop_back();

        // maxDeque.push_back(j);
        // minDeque.push_back(j);

        // ans+=nums[maxDeque.front()]-nums[minDeque.front()];
        //     }
        // }
        // return ans;

        int n = nums.size();
        stack<int> s;
        vector<long long int> leftMin(n, 0), leftMax(n, 0), rightMax(n, 0), rightMin(n, 0);

        // min elements
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && nums[s.top()] > nums[i])
                s.pop();
            leftMin[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }
        s = stack<int>();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && nums[s.top()] >= nums[i])
                s.pop();
            rightMin[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }
        // max elements
        s = stack<int>();
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && nums[s.top()] < nums[i])
                s.pop();
            leftMax[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }

        s = stack<int>();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && nums[s.top()] <= nums[i])
                s.pop();
            rightMax[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }
        long long ans = 0;
        for (int x = 0; x < n; x++)
        {
            long long MaxI = nums[x] * rightMax[x] * leftMax[x];
            long long MinI = nums[x] * rightMin[x] * leftMin[x];
            ans += MaxI - MinI;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    cout << s.subArrayRanges(nums);

    return 0;
}