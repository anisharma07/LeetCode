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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *newNode = new TreeNode(val);

        if (root == NULL)
        {
            return newNode;
        }
        TreeNode *ptr = root;
        while (ptr)
        {
            if (ptr->val > val)
            {
                if (ptr->left != NULL)
                    ptr = ptr->left;
                else
                {
                    ptr->left = newNode;
                    break;
                }
            }
            else
            {
                if (ptr->right != NULL)
                    ptr = ptr->right;
                else
                {
                    ptr->right = newNode;
                    break;
                }
            }
        }
        return root;
    }
};

int main()
{
    init_code();

    return 0;
}