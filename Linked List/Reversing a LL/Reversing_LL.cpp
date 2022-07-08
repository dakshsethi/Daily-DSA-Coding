#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int d) {
            data = d;
            next = NULL;
        }
};

void push(Node** head, int new_data)
{
    Node* new_node = new Node(new_data);
    new_node->next = *head;
    *head = new_node;
}

void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        cout<<node->data<<" -> "; 
        node = node->next; 
    }
    cout<<"NULL\n";
}

Node* reverse(Node* head) {
    Node *prevptr = NULL, *currptr = head, *nextptr = NULL;
    while(currptr != NULL) {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

Node* reverseRecursive(Node* head) {
    if(head == NULL || head->next == NULL)
        return head;
    Node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}


int main() {
    Node* head = new Node(6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printList(head);

    Node* newhead = reverse(head);
    cout<<"\nReversed LL using Iteration:\n";
    printList(newhead);
    
    Node* head1 = new Node(6);
    push(&head1, 5);
    push(&head1, 4);
    push(&head1, 3);
    push(&head1, 2);
    push(&head1, 1);

    Node* newhead2 = reverseRecursive(head1);
    cout<<"\nReversed LL using Recursion:\n";
    printList(newhead2);
    return 0;
}