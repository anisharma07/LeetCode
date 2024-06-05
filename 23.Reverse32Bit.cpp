#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int sign = x < 0 ? -1 : 1;
        long num = x;
        if (x < 0)
        {
            num = num * -1;
        }
        long reverse = 0;
        while (num > 0)
        {
            int digit = num % 10;
            reverse = reverse * 10 + digit;
            num = num / 10;
        }
        if (sign == -1)
        {
            if (reverse < INT_MIN)
            {
                return 0;
            }
            reverse = reverse * -1;
        }
        if (reverse > INT_MAX)
        {
            return 0;
        }
        return reverse;
    }
};

int main()
{
    Solution s;
    int x = 123;
    cout << s.reverse(x) << endl;

    return 0;
}