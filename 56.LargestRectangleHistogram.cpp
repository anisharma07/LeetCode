#include<iostream>
#include<vector>
#include<climits>
#include<stack>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &a)
    {
        int n = a.size();
        stack<int> stk;
        int leftMin[n], rightMin[n];
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && a[stk.top()] >= a[i])
                stk.pop();
            stk.empty() ? leftMin[i] = -1 : leftMin[i] = stk.top();
            stk.push(i);
        }
        while (!stk.empty())
            stk.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && a[stk.top()] >= a[i])
                stk.pop();
            stk.empty() ? rightMin[i] = n : rightMin[i] = stk.top();
            stk.push(i);
        }
        for (int i = 0; i < n; i++){
            cout<<leftMin[i]<<" ";
        }
        cout<<endl;
        for (int i = 0; i < n; i++){
            cout<<rightMin[i]<<" ";
        }
        cout << endl;
        int maxA = 0;
        for (int i = 0; i < n; i++)
        {
            int area = (rightMin[i] - leftMin[i] - 1) * a[i];
            maxA = max(maxA, area);
        }
        return maxA;
    }
};

int main(){
    Solution s;
    vector<int> a = {1,1};
    cout<<s.largestRectangleArea(a)<<endl;

    
    return 0;
}