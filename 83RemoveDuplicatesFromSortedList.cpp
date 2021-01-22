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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *curNode = head, *nextNode = head->next;
        while (nextNode != nullptr)
        {
            while (nextNode != nullptr && curNode->val == nextNode->val)
            {
                nextNode = nextNode->next;
                if (nextNode == nullptr)
                    break;
            }

            curNode->next = nextNode;
            curNode = curNode->next;
            if (nextNode != nullptr)
                nextNode = nextNode->next;
        }
        return head;
    }
};