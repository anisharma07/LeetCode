#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int width = sqrt(area);
        while (area % width != 0)
        {
            width--;
        }
        int length = area / width;
        return {length, width};
    }
};

int main()
{
    Solution s;
    vector<int> divei = s.constructRectangle(400);
    int n = divei.size();
    for (int i = 0; i < n; i++)
    {
        cout << divei[i] << " ";
    }
    return 0;
}