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
    void countNodes(TreeNode *root, int &count)
    {
        if (root == NULL)
            return;
        count++;
        countNodes(root->left, count);
        countNodes(root->right, count);
    }
    int getHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        int count = 0;
        countNodes(root, count);
        double height = getHeight(root);
        double logNumber = ceil(log(count) / log(2.0));
        return height <= logNumber;
    }
};

int main()
{
    init_code();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution obj;
    cout << obj.isBalanced(root);

    return 0;
}