#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;

        if (s.empty() && goal.empty())
            return true;

        for (int i = 0; i < s.size(); ++i)
        {
            s = s.substr(1) + s[0];
            if (s == goal)
                return true;
        }

        return false;
    }
};

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         int n=s.size();
//         if(s.size()!=goal.size()) return false;
//         string str=s+s;
//         if(str.find(goal)!=string::npos){
//             return true;
//         }
//         else return false;
//     }
// };

int main()
{
    Solution s;
    cout << s.rotateString("abcde", "cdeab") << endl;
    cout << s.rotateString("abcde", "abced") << endl;

    return 0;
}