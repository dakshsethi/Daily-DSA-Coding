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

void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->next = third;

    printList(head);
    return 0;
}