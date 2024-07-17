#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {

        // ***** HASHING *******

        int n = nums.size();
        // map<int, int> hash;
        // for(int i = 0; i<n; i++){
        //     hash[nums[i]]+=1;
        // }
        // for(auto it: hash){
        //     if(it.second==1) return it.first;
        // }
        // return -1;

        // ****** set bits ****
        int ans = 0;
        for (int i = 0; i <= 31; i++)
        {
            int count = 0;
            for (int num = 0; num < n; num++)
            {
                if (nums[num] & (1 << i))
                    count++;
            }
            cout<<count<<endl;
            if (count % 3 == 1)
                ans = ans | (1 << i);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,2,3,2,3,3,4,5,5,5};
    cout<<s.singleNumber(nums);

    return 0;
}