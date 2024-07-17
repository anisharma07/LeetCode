#include <bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Solution
{
public:
    int getTime(int k, vector<int> piles)
    {
        int time = 0;
        double x = k;
        for (int i = 0; i < piles.size(); i++)
        {
            time += ceil(piles[i] / x);
            cout << time << endl;
        }
        return time;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {

        sort(piles.begin(), piles.end());
        int n = piles.size();
        for (int k = 1; k <= piles[n - 1]; k++)
        {
            int reqTime = getTime(k, piles);
            if (reqTime <= h)
                return k;
        }
        return piles[n - 1];
    }
};

int main()
{
    init_code();

    Solution s;
    int n;
    cin >> n;
    vector<int> piles;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        piles.push_back(x);
    }
    int h;
    cin >> h;
    cout << s.minEatingSpeed(piles, h);
    cout << ceil(3 / 2);
    return 0;
}
