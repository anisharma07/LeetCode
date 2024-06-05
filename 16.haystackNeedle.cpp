#include <iostream>
#include <string>
using namespace std;

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int j =0;
//         int flag = 0;
//         int index = -1;
//         int i=0;
//         while(i!=haystack.length()){
//             if(haystack[i] == needle[0] && flag == 0)
//             {
//                 flag =1;
//                 index = i;
//             }
//             if(haystack[i] == needle[j]){
//                 j++;
//                 if(j==needle.length()) return index;
//             }else if(j!=0 && haystack[i] != needle[j]){
//                 i = index;
//                 flag = 0;
//                 j=0;
//             }
//             i++;
//         }
//         return -1;
//     }
// };

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        auto pos = haystack.find(needle);

        if (pos == std::string::npos)
        {
            return -1;
        }
        else
            return pos;
    }
};

int main()
{
    Solution s;
    cout << s.strStr("hello", "ll") << endl;
    cout << s.strStr("aaaaa", "bba") << endl;
    cout << s.strStr("", "") << endl;
    cout << s.strStr("a", "a") << endl;
    cout << s.strStr("mississippi", "issip") << endl;

    return 0;
}