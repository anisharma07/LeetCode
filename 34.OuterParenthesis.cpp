#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans = "";
        int ct = 0;
        for (char ch : s)
        {
            if (ch == '(' && ct == 0)
                ct++;
            else if (ch == '(' && ct >= 1)
            {
                ans += ch;
                ct++;
            }
            else if (ch == ')' && ct > 1)
            {
                ans += ch;
                ct--;
            }
            else if (ch == ')' && ct == 1)
                ct--;
        }
        return ans;
    }
};

int main()
{

    Solution s;
    cout << s.removeOuterParentheses("(()())(())") << endl;
    cout << s.removeOuterParentheses("(()())(())(()(()))") << endl;
    cout << s.removeOuterParentheses("()()") << endl;

    return 0;
}