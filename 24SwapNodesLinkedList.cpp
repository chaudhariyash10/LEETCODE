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

ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr)
        return head;
    if (head->next == nullptr)
        return head;

    ListNode *temp = head;

    head = head->next;

    temp->next = head->next;

    head->next = temp;

    temp->next = swapPairs(temp->next);
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

    li.head = swapPairs(li.head);

    showList(li.head);
}