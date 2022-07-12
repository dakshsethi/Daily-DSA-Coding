#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node() : data(0), next(nullptr){};
    Node(int x) : data(x), next(nullptr){};
};

void push(struct Node **head, int new_data)
{
    struct Node *new_node = new Node(new_data);
    new_node->next = *head;
    *head = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout<<node->data<<" -> ";
        node = node->next;
    }
    cout << "NULL\n";
}

bool detectLoop(struct Node *head)
{
    unordered_set<Node *> s;
    while (head != NULL)
    {
        if (s.find(head) != s.end())
            return true;
        s.insert(head);
        head = head->next;
    }
    return false;
}

void removeLoop(struct Node *head)
{
    unordered_set<Node *> s;
    while (head != NULL)
    {
        if (s.find(head->next) != s.end())
            head->next = NULL;
        s.insert(head);
        head = head->next;
    }
    cout<<"\nLoop Removed!!\n";
}

int main()
{
    struct Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    printList(head);

    // Loop Created Here
    head->next->next->next->next->next = head->next->next;
    // 5 -> 4 -> 3 -> 2 -> 1
    //           ^         |
    //           |         |
    //           -----------


    if (detectLoop(head)) cout<<"Loop Deteced!!";
    else  cout<<"Loop not Detected!!";

    removeLoop(head);

    if (detectLoop(head)) cout<<"Loop Deteced!!";
    else  cout<<"Loop not Detected!!";
    return 0;
}