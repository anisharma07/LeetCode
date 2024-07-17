#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define read(x) \
    int x;      \
    cin >> x
using namespace std;
void init_code()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        int l = 0;
        int flag = 0;
        for (int r = 0; r < n; r++)
        {
            if (flag == 0 && nums[r] > 0)
            {
                ans.push_back(nums[r]);
                nums[r] = 0;
                flag = 1;
            }
            if (flag == 1 && nums[r] < 0)
            {
                ans.push_back(nums[r]);
                nums[r] = 0;
                flag = 0;
            }

            while (l < r)
            {
                if (flag == 0 && nums[l] != 0 && nums[l] > 0)
                {
                    ans.push_back(nums[l]);
                    flag = 1;
                    l++;
                    break;
                }
                if (flag == 1 && nums[l] != 0 && nums[l] < 0)
                {
                    ans.push_back(nums[l]);
                    flag = 0;
                    l++;
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    init_code();
    int t = 1;
    cin >> t;
    while (t--)
    {
        read(a);
        read(b);
        cout << a + b << '\n';
    }
    return 0;
}