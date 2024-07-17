#include <bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        ans.push_back({root->val});
        int level = 1;
        while (!q.empty())
        {

            int size = q.size();
            vector<int> ds;
            for (int i = 0; i < size; i++)
            {
                TreeNode *Current = q.front();
                ds.push_back(Current->val);
                if (Current->left)
                    q.push(Current->left);
                if (Current->right)
                    q.push(Current->right);
            }
            if (level % 2 == 0)
                reverse(ds.begin(), ds.end());
            ans.push_back(ds);
            level++;
        }
        return ans;
    }
};

int main()
{
    init_code();

    return 0;
}