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

Node* mergeTwoLists(struct Node* list1, struct Node* list2) {
        struct Node *ptr = new Node(0);
        struct Node *curr = ptr;
        
        while(list1 != NULL && list2 != NULL) {
            if(list1->data <= list2->data) {
                curr -> next = list1;
                list1 = list1 -> next;
            }
            else {
                curr -> next = list2;
                list2 = list2 -> next;
            }
            curr = curr ->next;
        }
        
        //for unqual length linked list
        
        if(list1 != NULL) {
            curr -> next = list1;
            list1 = list1->next;
        }
        
        if(list2 != NULL) {
            curr -> next = list2;
            list2 = list2 ->next;
        }
        
        return ptr->next;
    }

int main() {
    struct Node* l1 = NULL;
    push(&l1, 5);
    push(&l1, 4);
    push(&l1, 2);
    push(&l1, 1);
    push(&l1, 1);

    cout<<"Linked List 1:\n";
    printList(l1);

    struct Node* l2 = NULL;
    push(&l2, 2);
    push(&l2, 4);
    push(&l2, 5);
    push(&l2, 7);
    push(&l2, 8);

    cout<<"Linked List 2:\n";
    printList(l2);

    struct Node* l3 = mergeTwoLists(l1, l2);
    cout<<"\nMerged Linked List:\n";
    printList(l3);

    return 0;
}