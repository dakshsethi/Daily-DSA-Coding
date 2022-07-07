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



int main() {
    Node* head = new Node(6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printList(head);

    Node* newhead = reverse(head);
    cout<<"\nReversed LL:\n";
    printList(newhead);
    return 0;
}