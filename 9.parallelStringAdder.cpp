#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "";
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i > 0 || j > 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';
            carry = sum / 2;
            result = to_string(sum % 2) + result;
        }
        return result;
    }
};

// class Solution {
// public:
//     string addBinary(string a, string b) {
//         int a_ptr = a.length() - 1;
//         int b_ptr = b.length() - 1;
//         int carry = 0;
//         char digit;
//         std::string res = "";
//         while (a_ptr >= 0 || b_ptr >=0 || carry) {
//             if (a_ptr >= 0) {
//                 carry += a[a_ptr--] - '0';
//             }
//             if (b_ptr >= 0) {
//                 carry += b[b_ptr--] - '0';
//             }
//             digit = carry%2 + '0';
//             res.insert(0, 1, digit);
//             carry = carry/2;
//         }
//         return res;
//     }
// };

int main()
{
    Solution s;
    cout << s.addBinary("11", "1");

    return 0;
}