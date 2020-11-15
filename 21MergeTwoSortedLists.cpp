#include <stdc++.h>
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode *t1, *t2;

        if (l1->val > l2->val)
        {
            ListNode *tmp = l1;
            l1 = l2;
            l2 = tmp;
        }

        t1 = l1;
        t2 = l2;

        while (t1->next)
        {
            if (t2->val < t1->next->val)
            {
                ListNode *tmp = t1->next;

                t1->next = t2;

                t2 = tmp;
            }
            t1 = t1->next;
        }

        if (t2)
            t1->next = t2;

        return l1;
    }
};