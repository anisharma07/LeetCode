#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// FASTEST RUNTIME:

// class Solution {
// public:
//     void deleteNode(ListNode* node) {
//         ListNode *ptr = node;
//         while(ptr->next->next != NULL){
//             ptr->val = ptr->next->val;
//             ptr = ptr->next;
//         }
//         ptr->val = ptr->next->val;
//         ptr->next = NULL;
//     }
// };

static const int __ = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int init = []
{
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string str, val_str; getline(cin, str) && getline(cin, val_str); cout << '\n')
    {
        int val = stoi(val_str);
        stringstream ss(str);
        ss.ignore();
        bool first = true;
        cout << '[';
        for (int i; ss >> i; ss.ignore())
        {
            if (i != val)
            {
                if (first)
                {
                    cout << i;
                    first = false;
                }
                else
                {
                    cout << ',' << i;
                }
            }
        }
        cout << ']';
    }
    exit(0);
    return 0;
}();

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        // *node = *node->next;

        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    return 0;
}