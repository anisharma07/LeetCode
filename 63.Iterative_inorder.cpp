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
struct  TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        fast_io;
        stack<TreeNode *> st;
        vector<int> ans;
        TreeNode *curr = root;
        while (curr != NULL || !st.empty())
        {
            if (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode *temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                
                if (temp->right == NULL && !st.empty())
                {
                        ans.push_back(st.top()->val);
                        curr = st.top()->right;
                        st.pop();
                }
                else
                {
                    curr = temp->right;
                }
            }
        }
        return ans;
    }
};

int main(){
    init_code();
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left = new TreeNode(1);
    vector<int> result = s.inorderTraversal(root);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}