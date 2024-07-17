#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        string str = "";
        unordered_map<char, int> hashMap;
        for (int i = 0; i < s.size(); i++)
        {
            hashMap[s[i]]++;
        }
        priority_queue<pair<int, char>> prq;
        for (auto it = hashMap.begin(); it != hashMap.end(); it++)
        {
            prq.push({it->second, it->first});
        }
        while (!prq.empty())
        {
            pair<int, char> p = prq.top();
            prq.pop();
            for (int i = 0; i < p.first; i++)
            {
                str += p.second;
            }
        }
        return str;
    }
};

int main()
{
    Solution s;
    string str = "Aabb";
    cout << s.frequencySort(str) << endl;

    return 0;
}