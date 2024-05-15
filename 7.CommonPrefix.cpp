#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        int n = strs.size();
        int m = strs[0].length();
        string s = "";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (strs[j][i] != strs[j + 1][i])
                {
                    return s;
                }
            }
            s = s + strs[0][i];
        }
        return s;
    }
};
// string longestCommonPrefix(vector<string>& strs) {
//     string res="";
//     string temp=strs[0];
//     for(string s: strs){
//         while(s.find(temp)!=0)
//             temp=temp.substr(0,temp.length()-1);
//     }
//     return temp;
//     }

int main()
{
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(strs);

    return 0;
}