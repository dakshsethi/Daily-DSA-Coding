#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_BUFFER 6

class Stack {
    int top;

    public:
        int arr[MAX_BUFFER]; // Maximum size of Stack

        Stack() { top = -1; }

        void push(int x) {
            if(top >= (MAX_BUFFER-1)) {
                cout<<"Stack Overflow!!\n";
            } else {
                arr[++top] = x;
                cout << x << " pushed into stack\n";
            }
        }

        int pop() {
            if(top < 0) {
                cout<<"Stack Underflow!!\n";
                return 0;
            } else {
                int x = arr[top--];
                return x;
            }
        }

        int peek() {
            if(top < 0) {
                cout<<"Stack is Empty!!";
                return 0;
            } else {
                int x = arr[top];
                return x;
            }
        }

        bool isEmpty()
        {
            return (top < 0);
        }
};

int main() {
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    cout << s.pop() << " Popped from stack\n";
    cout<<"Elements present in stack : ";
    while(!s.isEmpty())
    {
        cout<<s.peek()<<" ";
        s.pop();
    }
    return 0;
}