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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // cout << "list1: " << list1->val << endl;
        if (list1 == NULL && list2 == NULL)
        {
            return NULL;
        }
        else if (list1 == NULL)
        {
            return list2;
        }
        else if (list2 == NULL)
        {
            return list1;
        }
        ListNode *mergeHead, *temp;
        if (list1->val >= list2->val)
        {
            mergeHead = temp = list2;
            list2 = list2->next;
        }
        else
        {
            mergeHead = temp = list1;
            list1 = list1->next;
        }
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val > list2->val)
            {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
            else
            {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
        }
        if (list1 != NULL)
        {
            temp->next = list1;
        }
        else if (list2 != NULL)
        {
            temp->next = list2;
        }
        return mergeHead;
    }
};

int main()
{

    struct ListNode *list1 = NULL;
    struct ListNode *list2 = new ListNode(0);
    Solution s;
    struct ListNode *result = s.mergeTwoLists(list1, list2);
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}