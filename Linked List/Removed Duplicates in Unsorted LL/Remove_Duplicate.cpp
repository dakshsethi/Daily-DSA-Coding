#include <iostream>
#include <unordered_set>
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

void removeDuplicate(struct Node* head) {
    unordered_set<int> seen;
 
    /* Pick elements one by one */
    struct Node* curr = head;
    struct Node* prev = NULL;
    while (curr != NULL) {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete (curr);
        }
        else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 4);
    push(&head, 2);
    push(&head, 2);
    push(&head, 5);

    cout<<"Linked List with Duplicates:\n";
    printList(head);

    removeDuplicate(head);
    cout<<"\nLinked List Without Duplicates:\n";
    printList(head);

    return 0;
}