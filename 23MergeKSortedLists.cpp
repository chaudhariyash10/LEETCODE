//Linked list ans;

#include <bits/stdc++.h>
using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
//     {
//         ListNode *curNode = new ListNode(-1);

//         ListNode *head = curNode;

//         while (l1 != nullptr && l2 != nullptr)
//         {
//             if (l2->val < l1->val)
//             {
//                 curNode->next = l2;
//                 l2 = l2->next;
//             }
//             else
//             {
//                 curNode->next = l1;
//                 l1 = l1->next;
//             }
//             curNode = curNode->next;
//         }

//         while (l1 != nullptr)
//         {
//             curNode->next = l1;
//             l1 = l1->next;
//             curNode = curNode->next;
//         }
//         while (l2 != nullptr)
//         {
//             curNode->next = l2;
//             l2 = l2->next;
//             curNode = curNode->next;
//         }
//         return head -> next;
//     }

//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         if (lists.size() == 0)
//             return nullptr;
//         if (lists.size() == 1)
//             return lists[0];

//         ListNode *ans;
//         ans = lists[0];

//         for (int i = 1; i < lists.size(); i++)
//         {
//            ans =  mergeTwoLists(ans, lists[i]);
//         }

//         return ans;
//     }
// };

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.size() == 0)
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        vector<int> temp;

        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *head = lists[i];

            while (head != nullptr)
            {
                temp.push_back(head->val);
                head = head->next;
            }
        }

        sort(temp.begin(), temp.end());

        ListNode *head = (ListNode*)new ListNode(temp[0]);
        ListNode *curNode = head;
        for (int i = 1; i < temp.size(); i++)
        {
            ListNode *temp1 = (ListNode *)new ListNode(temp[i]);

            curNode->next = temp1;
            curNode = curNode->next;
        }
        return head;
    }
};