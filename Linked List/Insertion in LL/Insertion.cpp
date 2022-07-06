#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        cout<<node->data<<" -> "; 
        node = node->next; 
    }
    cout<<"NULL\n";
}

void insertAtFront(Node** head, int new_data) {
    /* 1. allocate node */
    Node* new_node = new Node();

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. Make next of new node as head */
    new_node->next = *head;

    /* 4. move the head to point to the new node */
    *head = new_node;
}

void insertAtEnd(Node** head, int new_data) {
    /* 1. allocate node */
    Node* new_node = new Node();

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if(*head ==  NULL) {
        *head = new_node;
        return ;
    }

    Node* last = *head;

    /* 5. Else traverse till the last node */
    while(last->next != NULL) {
        last = last->next;
    }

    /* 6. Change the next of last node */
    last->next = new_node;
    return ;
}

void insertAfter(Node* prev_node, int new_data) {
    /*1. check if the given prev_node is NULL */
    if(prev_node == NULL) {
        cout<<"The given previous node cannot be NULL"; 
        return; 
    }

    /* 2. allocate new node */
    Node* new_node = new Node();

    /* 3. put in the data */
    new_node->data = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}

int main() {
    Node* head = NULL;
    cout<<"Insert At Front: "<<endl;
    insertAtFront(&head, 5);
    printList(head);
    insertAtFront(&head, 2);
    printList(head);
    insertAtFront(&head, 1);
    printList(head);

    cout<<"\nInsert At End: "<<endl;
    insertAtEnd(&head, 6);
    printList(head);
    insertAtEnd(&head, 7);
    printList(head);

    cout<<"\nInsert After: "<<endl;
    insertAfter(head->next, 3);
    printList(head);
    insertAfter(head->next->next, 4);
    printList(head);
    return 0;
}