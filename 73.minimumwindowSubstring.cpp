#include<bits/stdc++.h>
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
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;
void init_code() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length();
        string ans = "";
        int minLength = INT_MAX;
        vector<int> hashmap(256, 0);
        for (int x = 0; x < t.length(); x++)
        {
            hashmap[t[x] - '0'] += 1;
        }
        int count = 0;
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            hashmap[s[r] - '0'] -= 1;
            if (hashmap[s[r] - '0'] >= 0)
                count++;
            if (count == t.length())
            {
                if (r - l + 1 < minLength)
                {
                    minLength = r - l + 1;
                    ans = s.substr(l, r - l + 1);
                }
            }
            while (count >= t.length())
            {
                hashmap[s[l] - '0'] += 1;
                if (hashmap[s[l] - '0'] > 0)
                {
                    count--;
                    l++;
                }
                else
                {
                    l++;
                    if (r - l + 1 < minLength)
                    {
                        minLength = r - l + 1;
                        ans = s.substr(l, r - l + 1);
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    init_code();
    int t = 1;
    cin >> t;
    while (t--){
        read(a);
        read(b);
        cout << a + b << '\n';
    }
    return 0;
}