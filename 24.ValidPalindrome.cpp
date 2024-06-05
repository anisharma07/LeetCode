#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
#include <ctype.h>
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
        return false;
    }
    bool isPalindrome(string s)
    {
        int n = s.size();
        int last = n - 1;
        int first = 0;
        while (first < last)
        {
            if (isValidChar(tolower(s[first])) && isValidChar(tolower(s[last])))
            {
                if (tolower(s[first]) != tolower(s[last]))
                {
                    return false;
                }
                first++;
                last--;
            }
            if (!isValidChar(tolower(s[first])))
            {
                first++;
            }
            if (!isValidChar(tolower(s[last])))
            {
                last--;
            }
        }

        return true;
    }
};
int main()
{
    Solution s;
    if (s.isPalindrome("Anirudh Sharma"))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}