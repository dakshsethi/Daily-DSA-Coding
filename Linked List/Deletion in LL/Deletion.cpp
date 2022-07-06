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

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    if(temp != NULL && temp->data == key ) {
        *head = temp->next;
        delete temp;
        return ;
    } else {
        while(temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
            return ;

        prev->next = temp->next;
        delete temp;
    }
}

int main() {
    Node* head = new Node(6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printList(head);

    cout<<"\nDeleting 1:\n";
    deleteNode(&head, 1);
    printList(head);

    cout<<"\nDeleting 3:\n";
    deleteNode(&head, 3);
    printList(head);
    return 0;
}