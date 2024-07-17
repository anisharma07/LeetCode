#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isValidChar(char c)
    {
        if (isalpha(c) || isdigit(c))
        {
            return true;
        }
    }
    string reverseWords(string s)
    {
        int n = s.size();
        string result = "";
        string word = "";
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (isValidChar(s[i]))
            {
                word += s[i];
                if (i == n - 1 || s[i + 1] == ' ')
                {

                    if (flag)
                    {
                        result = word + ' ' + result;
                        word = "";
                        // cout << "flag 1: " << result << endl;
                    }
                    if (!flag)
                    {
                        result = word + result;
                        word = "";
                        flag = true;
                        // cout << "" << result << endl;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    string str = "EPY2giL";
    cout << s.reverseWords(str) << endl;

    return 0;
}