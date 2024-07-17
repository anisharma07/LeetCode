#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        vector<int> hash(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < t.size(); i++)
        {
            hash[t[i] - 'a'] -= 1;
            if (hash[t[i] - 'a'] == -1)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    string s1 = "anagram";
    string s2 = "nagaram";
    cout << s.isAnagram(s1, s2) << endl;

    return 0;
}