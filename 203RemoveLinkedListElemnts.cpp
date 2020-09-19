#include <iostream>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class linkedList
{
public:
    ListNode *head;

    linkedList()
    {
        this->head = nullptr;
    }
};

ListNode *insert(ListNode *head, int val)
{
    ListNode *newListNode = new ListNode(val);
    if (head == nullptr)
    {
        head = newListNode;
        return head;
    }

    newListNode->next = head;
    head = newListNode;

    return head;
}

void showList(ListNode *head)
{
    if (head == nullptr)
        return;

    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << "\t";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *removeElements(ListNode *head, int val)
{
    if (head == nullptr)
        return head;
    ListNode *current = head;
    ListNode *prev = nullptr;

    while (current != nullptr)
    {
        if (current->val == val)
        {
            while (current->val == val)
            {
                current = current->next;
            }

            prev = current;
            current = current->next;
        }

        else
        {
            prev = current;
            current = current->next;
        }
    }

    return head;
}



int main()
{
    linkedList li;

    li.head = insert(li.head, 6);
    li.head = insert(li.head, 5);
    li.head = insert(li.head, 4);
    li.head = insert(li.head, 3);
    li.head = insert(li.head, 6);
    li.head = insert(li.head, 2);
    li.head = insert(li.head, 1);

    //li.head = removeElements(li.head, 6);

 

    showList(li.head);
}