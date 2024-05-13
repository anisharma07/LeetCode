// fastest response palindrome
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        int reversedNum = 0;
        int originalNum = x;
        while (x > 0)
        {
            int digit = x % 10;
            if (reversedNum > (INT16_MAX / 10))
            {
                return false;
            }
            if (reversedNum == (INT16_MAX) && digit > (INT16_MAX % 10))
            {
                return false;
            }
            reversedNum = reversedNum * 10 + digit;
            x /= 10;
        }
        return reversedNum == originalNum;
    }
};

int main()
{
    Solution s;
    int x = 1234567899;
    cout << s.isPalindrome(x);

    return 0;
}