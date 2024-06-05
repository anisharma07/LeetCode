#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        static auto isSpace = [](char c)
        { return c == ' '; };

        auto endOfLastWordIt = find_if_not(s.crbegin(), s.crend(), isSpace);
        auto startOfLastWordIt = find_if(endOfLastWordIt, s.crend(), isSpace);

        return distance(endOfLastWordIt, startOfLastWordIt);
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLastWord("Hello World") << endl;

    return 0;
}