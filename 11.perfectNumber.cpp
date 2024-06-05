#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        int sum = 0;

        for (int i = 2; i < sqrt(num); i++)
        {
            if (num % i == 0)
            {
                sum = sum + i + num / i;
                cout << " i-> " << sum;
            }
        }
        cout << endl;
        if (num != 1)
        {
            sum += 1;
        }

        return sum == num;
    }
};

int main()
{

    Solution s;
    cout << s.checkPerfectNumber(28);

    return 0;
}