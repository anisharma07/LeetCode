#include<iostream>
#include<vector>
#include<climits>
#include<stack>
using namespace std;

class Solution
{
public:
    int largestRectangle(vector<int> &a)
    {
        int n = a.size();
        int maxA = 0;

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
        for (int i = 0; i < n; i++)
        {
            int area = (rightMin[i] - leftMin[i] - 1) * a[i];
            maxA = max(maxA, area);
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> arr(m, 0);
        int maxA = 0;
        for (int i = 0; i < n; i++)
        {
            // update current histogram
            for (int j = 0; j < m; j++)
            {
                if (arr[j] == 0)
                    arr[j] = matrix[i][j] - '0';
                else
                    arr[j] += matrix[i][j] - '0';
            }
            maxA = max(maxA, largestRectangle(arr));
        }
        return maxA;
    }
};
int main(){
    Solution s;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'}};
    cout<<s.maximalRectangle(matrix)<<endl;

    return 0;
}