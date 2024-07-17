#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int m = 1e9 + 7;
    int mul(int a, int b)
    {
        a %= m;
        b %= m;
        return (1LL * a * b) % m;
    }
    int sumSubarrayMins(vector<int> &arr)
    {
        // int n = arr.size();
        // vector<int> l(n, 0), r(n, 0);
        // int MOD = 1e9 + 7;
        // stack<int> stk;
        // for (int i = 0; i < n; i++)
        // {
        //     while (!stk.empty() && arr[stk.top()] > arr[i])
        //     {
        //         stk.pop();
        //     }
        //     l[i] = stk.empty() ? i + 1 : i - stk.top();
        //     stk.push(i);
        // }
        // while (!stk.empty())
        //     stk.pop();
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     while (!stk.empty() && arr[stk.top()] >= arr[i])
        //         stk.pop();
        //     r[i] = stk.empty() ? n - i : stk.top() - i;
        //     stk.push(i);
        // }
        // long ans = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     ans = (ans + (long long)arr[i] * r[i] * l[i]) % MOD;
        // }
        // return (int)ans;
        int n = arr.size();
        int nsi[n], psi[n];
        int ans = 0;
        // nsi
        for (int i = n - 1; i >= 0; i--)
        {
            nsi[i] = i + 1;
            while (nsi[i] != n and arr[nsi[i]] >= arr[i])
            {
                nsi[i] = nsi[nsi[i]];
            }
        }
        // psi
        for (int i = 0; i < n; i++)
        {
            psi[i] = i - 1;
            while (psi[i] != -1 and arr[psi[i]] > arr[i])
            {
                psi[i] = psi[psi[i]];
            }
        }
        for (int i = 0; i < n; i++)
        {
            int a = (1LL * arr[i] * (i - nsi[i]) * (psi[i] - i)) % m;
            ans = (ans + a) % m;
        }
        return (((ans % m) + m) % m);
    }
};

int main()
{
    Solution s;
    vector<int> arr = {3, 1, 2, 4};
    cout << s.sumSubarrayMins(arr);
    return 0;
}