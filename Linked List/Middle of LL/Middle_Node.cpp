#include <iostream>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;

        ListNode(int d)
        {
            val = d;
            next = NULL;
        }
};

void push(ListNode **head, int new_data)
{
    ListNode *new_node = new ListNode(new_data);
    new_node->next = *head;
    *head = new_node;
}

void printList(ListNode *node)
{
    while (node != NULL)
    {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "NULL\n";
}

ListNode *middleNode(ListNode *head)
{
    if (head->next == NULL) return head;
    if (head->next->next == NULL) return head->next;

    int count = 0, mid = 0;
    ListNode *start = head;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    if (count % 2 == 0)
        mid = count / 2 + 1;
    else
        mid = (count + 1) / 2;

    while (mid > 1)
    {
        start = start->next;
        mid--;
    }

    return start;
}

int main()
{
    ListNode *head = new ListNode(6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Linked List:\n";
    printList(head);

    cout << "\nMiddle Node:\n";
    cout << middleNode(head)->val;
    return 0;
}