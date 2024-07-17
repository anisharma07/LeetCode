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
    bool lemonadeChange(vector<int> &bills)
    {
        map<int, int> mp;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                mp[5] += 1;
            }
            if (bills[i] == 10)
            {
                if (mp[5] > 0)
                {
                    mp[5] -= 1;
                    mp[10] += 1;
                }
                else
                {
                    return false;
                }
            }
            if (bills[i] == 20)
            {
                int temp = 20;
                if (mp[10] > 0)
                {
                    mp[10] -= 1;
                    temp = 10;
                }
                while (temp != 5)
                {
                    if (mp[5] > 0)
                    {
                        mp[5] -= 1;
                        temp -= 5;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
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