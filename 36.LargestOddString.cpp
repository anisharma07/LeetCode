#include <iostream>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.size();
        if ((num[n - 1] - '0') % 2 != 0)
        {
            return num;
        }
        int flag = 0;
        string s = "";
        for (int i = n - 1; i >= 0; i--)
        {
            if (flag == 1)
            {
                s = num[i] + s;
            }
            if (flag == 0)
            {
                if ((num[i] - '0') % 2 != 0)
                {
                    s += num[i];
                    flag = 1;
                }
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.largestOddNumber("35427") << endl;

    return 0;
}