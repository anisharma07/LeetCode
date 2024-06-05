#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; i++)
        {
            int flag1 = 0;
            int flag2 = 0;
            for (int j = 0; j < m; j++)
            {
                if (flag2 == 1 && nums2[j] > nums1[i])
                {
                    ans.push_back(nums2[j]);
                    flag1 = 1;
                    break;
                }
                if (nums1[i] == nums2[j])
                    flag2 = 1;
            }
            if (flag1 == 0)
                ans.push_back(-1);
        }

        return ans;
    }
};

// class Solution {      // fastest runtime
// public:
//     vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
//         vector<int> ans;
//         unordered_map<int,int> m;
//         stack<int> st;
//         for(auto i:b){
//             while(!st.empty() && st.top()<i){
//                 m[st.top()]=i;
//                 st.pop();
//             }
//             st.push(i);
//         }
//         for(auto i:a){
//             if(m.find(i)!=m.end()) ans.push_back(m[i]);
//             else ans.push_back(-1);
//         }
//         return ans;
//     }
// };

int main()
{
    Solution s;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> divei = s.nextGreaterElement(nums1, nums2);
    int n = divei.size();
    for (int i = 0; i < n; i++)
    {
        cout << divei[i] << " ";
    }
    return 0;
}