#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int getRound(string strr, int sign)
    {
        if (strr.length() > 10)
        {
            if (sign == -1)
            {
                return INT32_MIN;
            }
            else
            {
                return INT32_MAX;
            }
        }
        long x = 0;
        for (int i = 0; i < strr.size(); i++)
        {
            x = x * 10 + (strr[i] - '0');
        }
        x = x * sign;
        if (x > INT32_MAX)
        {
            return INT32_MAX;
        }
        if (x < INT32_MIN)
        {
            return INT32_MIN;
        }
        return (int)x;
    }
    int myAtoi(string s)
    {
        string str = "";
        int sign = 1;
        int gotDigit = 0;
        int gotZero = 0;
        for (char c : s)
        {
            if (isalpha(c) || c == '.')
            {
                break;
            }
            if (gotZero || gotDigit)
            {
                if (c == '-' || c == '+')
                {
                    break;
                }
            }
            if (!gotZero)
            {
                if (c == '0' || c == '+' || c == '-')
                    gotZero = 1;
            }

            if (gotDigit)
            {
                if (c == ' ')
                {
                    break;
                }
                if (isdigit(c))
                {
                    str += c;
                }
            }
            if (c != '0' && !gotDigit)
            {
                if (c == '-')
                {
                    sign = -1;
                }
                if (isdigit(c))
                {
                    str += c;
                    gotDigit = 1;
                }
            }
        }
        cout << str << endl;
        if (str == "")
            return 0;
        return getRound(str, sign);
    }
};

int main()
{
    Solution s;
    string str = "  0000000000012345678";
    cout << s.myAtoi(str) << endl;

    return 0;
}