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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    stack<TreeNode *> st1, st2;

public:
    // Concept : Use two sum & iterator problem's concept.
    void setInitials(TreeNode *root)
    {
        TreeNode *ptr = root;
        st1.push(ptr);
        while (ptr->left != NULL)
        {
            ptr = ptr->left;
            st1.push(ptr);
        }

        st2.push(root);
        while (root->right != NULL)
        {
            root = root->right;
            st2.push(root);
        }
    }

    int next()
    {
        if (st1.empty())
            return -1;
        TreeNode *temp = st1.empty() ? NULL : st1.top();
        st1.pop();
        int data = temp->val;

        if (temp->right)
        {
            TreeNode *ptr = temp->right;
            st1.push(ptr);
            while (ptr->left != NULL)
            {
                ptr = ptr->left;
                st1.push(ptr);
            }
        }
        return data;
    }

    int before()
    {
        if (st2.empty())
            return -1;
        TreeNode *temp = st2.top();
        st2.pop();
        int data = temp->val;

        if (temp->left)
        {
            TreeNode *ptr = temp->left;
            st2.push(ptr);
            while (ptr->right != NULL)
            {
                ptr = ptr->right;
                st2.push(ptr);
            }
        }
        return data;
    }

    bool findTarget(TreeNode *root, int k)
    {
        if (root == NULL)
            return false;
        setInitials(root);
        int i = next();
        int j = before();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
            {
                i = next();
            }
            else
            {
                j = before();
            }
        }
        return false;
    }
};

int main()
{
    init_code();

    return 0;
}