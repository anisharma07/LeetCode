#include <iostream>
using namespace std;

bool checkIfPalindrome(string s)
{
    int n = s.size();
    int i = 0;
    while (i < n - i - 1)
    {
        if (s[i] != s[n - i - 1])
            return false;
        i++;
    }
    return true;
}
int main()
{
    string s = "aaaaaa";
    cout << checkIfPalindrome(s);

    return 0;
}