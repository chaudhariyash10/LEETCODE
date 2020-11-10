#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *ans = (ListNode *)new ListNode(-1);

        ListNode *curNode = ans, *temp = head;

        while (temp != nullptr)
        {
            curNode->next = temp;
            curNode = curNode->next;
            curNode->next = nullptr;
            
        }

        return ans->next;
    }
};