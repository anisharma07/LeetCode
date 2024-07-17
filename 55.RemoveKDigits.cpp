#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        if (n == k)
            return "0";

        string str = "";
        stack<char> stk;

        for (char c : num)
        {
            while (!stk.empty() && stk.top() > c && k > 0)
            {
                stk.pop();
                k--;
            }
            stk.push(c);
        }
        while (!stk.empty() && k > 0)
        {
            stk.pop();
            k--;
        }
        while (!stk.empty())
        {
            cout << stk.top() << endl;
            str = stk.top() + str;
            stk.pop();
        }

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != '0')
                return str.substr(i);
            if (i == str.size() - 1 && str[i] == '0')
                return "0";
        }
        return str.empty() ? "0" : str;
    }
};
int main()
{
    Solution s;
    string num = "112";
    int k = 1;
    cout << s.removeKdigits(num, k) << endl;

    return 0;
}