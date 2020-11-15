//Linked list ans;

#include <bits/stdc++.h>
using namespace std;

//Merging two lists at a time

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

//Copying the elements and returning a sorted array
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
//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {

//         if (lists.size() == 0)
//             return nullptr;
//         if (lists.size() == 1)
//             return lists[0];
//         vector<int> temp;

//         for (int i = 0; i < lists.size(); i++)
//         {
//             ListNode *head = lists[i];

//             while (head != nullptr)
//             {
//                 temp.push_back(head->val);
//                 head = head->next;
//             }
//         }

//         sort(temp.begin(), temp.end());

//         ListNode *head = (ListNode*)new ListNode(temp[0]);
//         ListNode *curNode = head;
//         for (int i = 1; i < temp.size(); i++)
//         {
//             ListNode *temp1 = (ListNode *)new ListNode(temp[i]);

//             curNode->next = temp1;
//             curNode = curNode->next;
//         }
//         return head;
//     }
// };

//Best Solution

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
//     {
//         if (!l1)
//             return l2;
//         if (!l2)
//             return l1;

//         ListNode *t1, *t2;

//         if (l1->val > l2->val)
//         {
//             ListNode *tmp = l2;
//             l2 = l1;
//             l1 = tmp;
//         }
//         t1 = l1;
//         t2 = l2;

//         while (t1->next)
//         {
//             if (t1->next->val > t2->val)
//             {
//                 //point to t2
//                 ListNode *tmp = t1->next;
//                 t1->next = t2;
//                 //swap t1 and t2
//                 t2 = tmp;
//                 t1 = t1->next;
//             }
//             else
//                 t1 = t1->next;
//         }
//         if (t2)
//             t1->next = t2;
//         return l1;
//     }

//     ListNode *merge(vector<ListNode *> &lists, int m, int n)
//     {
//         if (m == n)
//         {
//             return lists[m];
//         }
//         if (n - m == 1)
//         {
//             return mergeTwoLists(lists[m], lists[n]);
//         }

//         return mergeTwoLists(merge(lists, m, m + (n - m) / 2), merge(lists, m + (n - m) / 2 + 1, n));
//     }

//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {

//         int n = lists.size();
//         if (n == 0)
//             return {};
//         if (n == 1)
//             return lists[0];

//         ListNode *result = merge(lists, 0, n - 1);

//         return result;
//     }
// };
//
//
//
//

