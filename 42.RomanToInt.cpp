#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int n = s.size();
        int count = 0, flag = 0;
        int prev = 0;
        map<char, int> val = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = n - 1; i >= 0; i--)
        {
            if (flag == 0)
            {
                count += val[s[i]];
                flag = 1;
                prev = count;
            }
            else
            {
                if (val[s[i]] >= prev)
                {
                    count += val[s[i]];
                    prev = val[s[i]];
                }
                if (val[s[i]] < prev)
                {
                    count -= val[s[i]];
                    prev = val[s[i]];
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    string str = "XCIX";
    cout << s.romanToInt(str) << endl;

    return 0;
}