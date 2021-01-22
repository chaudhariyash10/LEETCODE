#include <iostream>

using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data)
    {
        this->data = data;
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

ListNode *insert(ListNode *head, int data)
{
    ListNode *newListNode = new ListNode(data);
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
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *reverseListIteration(ListNode *head)
{
    ListNode *p2 = head;
    ListNode *p1 = nullptr;

    while (p2 != nullptr)
    {
        ListNode *p3 = p2->next;

        p2->next = p1;

        p1 = p2;
        p2 = p3;
    }

    head = p1;

    return head;
}

ListNode *helper(ListNode *head, ListNode *current)
{

    if (current->next == nullptr)
    {
        head = current;
        return head;
    }

    else
    {
        head = helper(head, current->next);

        ListNode *temp = current->next;
        temp->next = current;
        current->next = nullptr;

        return head;
    }
}

ListNode *reverseListRecursion(ListNode *head)
{

    if (head == nullptr)
        return head;
        
    head = helper(head, head);
    return head;
}
int main()
{
    linkedList li;
    li.head = insert(li.head, 1);
    li.head = insert(li.head, 2);
    li.head = insert(li.head, 3);
    li.head = insert(li.head, 4);
    li.head = insert(li.head, 5);
    showList(li.head);

    li.head = reverseListRecursion(li.head);
    showList(li.head);
}