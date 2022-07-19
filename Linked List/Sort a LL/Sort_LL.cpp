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

void sortList(struct Node* head) {
    if(head == NULL || head->next) return ;//head;
        
    struct Node* start = head;
    struct Node* next = NULL;
    while(start->next != NULL) {
        next = start->next;
        while(next != NULL) {
            if(next->data < start->data) {
                int temp = next->data;
                next->data = start->data;
                start->data = temp;
            }
            next = next->next;
        }
        start = start->next;
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    cout<<"Linked List:\n";
    printList(head);

    sortList(head);
    cout<<"\nSorted Linked List:\n";
    printList(head);

    return 0;
}