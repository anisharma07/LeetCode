#include<bits/stdc++.h>
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

vector<int> preorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};
    stack<TreeNode *> st;
    vector<int> ans;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *topEle = st.top();

        ans.push_back(topEle->val);

        st.pop();

        if (topEle->right)
        {
            st.push(topEle->right);
        }
        if (topEle->left)
        {
            st.push(topEle->left);
        }
    }
    // vector<int> result;
    // preorder(root, result);
    return ans;
}

int main(){
init_code();
TreeNode *root = new TreeNode(1);
root->right = new TreeNode(2);
root->right->left = new TreeNode(3);
vector<int> result = preorderTraversal(root);
for(int i=0; i<result.size(); i++){
    cout<<result[i]<<" ";
}

return 0;
}