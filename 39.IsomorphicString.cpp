#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.size();
        unordered_map<char, char> map_s_to_t;
        unordered_map<char, char> map_t_to_s;

        if (s.size() != t.size())
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            if (map_s_to_t.find(s[i]) != map_s_to_t.end())
            {
                if (map_s_to_t[s[i]] != t[i])
                    return false;
            }
            else
            {
                map_s_to_t[s[i]] = t[i];
            }

            if (map_t_to_s.find(t[i]) != map_t_to_s.end())
            {
                if (map_t_to_s[t[i]] != s[i])
                    return false;
            }
            else
            {
                map_t_to_s[t[i]] = s[i];
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    string s1 = "egg";
    string s2 = "add";
    cout << s.isIsomorphic(s1, s2) << endl;

    return 0;
}