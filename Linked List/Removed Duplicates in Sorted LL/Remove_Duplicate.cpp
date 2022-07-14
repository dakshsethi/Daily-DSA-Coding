#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(): data(0), next(nullptr) {}
    Node(int x): data(x), next(nullptr) {}
};

void printList(struct Node* node) {
    while(node != NULL) {
        cout<<node->data<<" -> ";
        node = node->next;
    }
    cout<<"NULL\n";
}

void push(struct Node** head, int new_data) {
    struct Node* new_node = new Node(new_data);
    new_node->next = *head;
    *head = new_node;
}

void removeDuplicates(struct Node* head) {
    struct Node* curr = head;
    struct Node* prev = head;

    while(curr != NULL) {
        if(curr->data != prev->data) {
            prev->next = curr;
            prev = curr;
        }
        curr = curr->next;
    }

    if(prev != curr)
        prev->next = NULL;
}

int main() {
    struct Node* head = NULL;
    push(&head, 5);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 3);
    push(&head, 3);
    push(&head, 2);
    push(&head, 2);
    push(&head, 1);

    cout<<"Sorted Linked List with Duplicates:\n";
    printList(head);

    removeDuplicates(head);
    cout<<"\nSorted Linked List without Duplicates:\n";
    printList(head);
    return 0;
}