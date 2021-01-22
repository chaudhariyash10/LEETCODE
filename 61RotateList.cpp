#include<stdc++.h>
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *newTemp = head, *temp= head;
        int i = 0;
        while(temp->next != nullptr)
        {
            i++;
            temp = temp->next;
        }
        i++;
        k = k % i;

        temp->next = head;
        
        for (int j = 0; j < i - k-1 ; j++)
            newTemp = newTemp->next;

        head = newTemp->next;
        newTemp->next = nullptr;

        return head;
    }
};