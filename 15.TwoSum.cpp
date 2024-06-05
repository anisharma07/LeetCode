#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        int carry = 0;
        int first = 0;
        int second = 0;
        int sum = 0;
        ListNode *newHead = NULL;
        while (l1 != NULL || l2 != NULL)
        {

            first = l1 ? l1->val : 0;
            second = l2 ? l2->val : 0;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;

            sum = carry + first + second;
            carry = sum / 10;

            if (newHead == NULL)
            {
                newHead = new ListNode(sum % 10);
            }
            else
            {
                ListNode *newNode = new ListNode(sum % 10);
                ListNode *ptr = newHead;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = newNode;
            }
        }
        if (carry != 0)
        {
            ListNode *newNode = new ListNode(carry);
            ListNode *ptr = newHead;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
        return newHead;
    }
};

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//     {
//         ListNode* ans = new ListNode();
//         ListNode* curr = ans;
//         int carry = 0, val1, val2, sum, val;

//         while(l1 || l2 || carry)
//         {
//             if(l1) val1 = l1->val;
//             else val1 = 0;

//             if(l2) val2 = l2->val;
//             else val2 = 0;

//             sum = val1 + val2 + carry;
//             carry = sum/10;
//             val = sum%10;

//             curr->next = new ListNode(val);
//             curr = curr->next;

//             if(l1) l1 = l1->next;
//             else l1 = nullptr;

//             if(l2) l2 = l2->next;
//             else l2 = nullptr;
//         }
//         return ans->next;
//     }
// };

int main()
{
    Solution s;
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode *l3 = s.addTwoNumbers(l1, l2);
    while (l3 != nullptr)
    {
        cout << l3->val << " ";
        l3 = l3->next;
    }

    return 0;
}