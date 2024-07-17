#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> stk;
        for (int x : asteroids)
        {
            if (stk.empty())
            {
                stk.push(x);
            }
            else
            {
                if (stk.top() > 0 && x < 0)
                {
                    if (abs(stk.top()) < abs(x))
                    {
                        while (!stk.empty() && stk.top() > 0 && stk.top() < abs(x))
                        {
                            stk.pop();
                        }
                        if (stk.top() > 0 && abs(x) == stk.top())
                            stk.pop();
                        else
                            stk.push(x);
                    }
                    else if (abs(stk.top()) == abs(x))
                        stk.pop();
                }
                else
                {
                    stk.push(x);
                }
            }
        }
        vector<int> ans;
        while (!stk.empty())
        {
            ans.insert(ans.begin(), stk.top());
            stk.pop();
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> asteroids = {5, 10, -5};
    vector<int> ans = s.asteroidCollision(asteroids);
    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}