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
            if (curNode->next != nullptr)
            {
                if (curNode->next->val == temp->val)
                {
                    while (temp != nullptr && temp->val == curNode->next->val)
                        temp = temp->next;

                    curNode->next = nullptr;
                }
                else
                {
                    curNode->next->next = temp;
                    curNode = curNode->next;
                    
                    temp = temp->next;
                }
            }
            else
            {
                curNode->next = temp;
                
                temp = temp->next;
            }
        }

        return ans->next;
    }
};