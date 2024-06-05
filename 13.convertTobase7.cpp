#include <iostream>
using namespace std;

class Solution
{
public:
    string convertToBase7(int num)
    {
        int n = abs(num);
        int Factor = 1;
        int Ans1 = 0;
        while (Factor <= n)
            Factor *= 7;
        Factor /= 7;
        while (Factor > 0)
        {
            Ans1 = Ans1 * 10 + n / Factor;
            n %= Factor;
            Factor /= 7;
        }
        if (num < 0)
            Ans1 *= -1;
        string Ans2 = to_string(Ans1);
        return Ans2;
    }
};

int main()
{

    Solution s;
    cout << s.convertToBase7(100);

    return 0;
}