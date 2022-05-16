#include <iostream>
#include <stdlib.h>
using namespace std;

class twoStacks {
    int top1, top2;
    int size;
    int* arr;

    public:
        twoStacks(int n) {
            size = n;
            arr = new int[n];
            top1 = n/2+1;
            top2 = n/2;
            cout<<"Size of Stack 1 = "<<top1;
            cout<<"\nSize of Stack 2 = "<<top2;

            for(int i=0; i<size; i++)
                arr[i] = -1;
        }

        void push1(int x) {
            if(top1 > 0) {
                arr[--top1] = x;
                cout<<"\nPushed "<<x<<" into stack 1";
            } else {
                cout<<"\nStack 1 Overflow!!";
                return;
            }
        }

        void push2(int x) {
            if(top2 < size-1) {
                arr[++top2] = x;
                cout<<"\nPushed "<<x<<" into stack 2";
            } else {
                cout<<"\nStack 2 Overflow!!";
                return;
            }
        }

        int pop1() {
            if(top1 <= size/2) {
                int x = arr[top1];
                arr[top1] = -1;
                top1++;
                return x;
            } else {
                cout<<"\nStack 1 Underflow!!";
                exit(1);
            }
        }

        int pop2() {
            if(top2 >= size/2 + 1) {
                int x = arr[top2];
                arr[top2] = -1;
                top2--;
                return x;
            } else {
                cout<<"\nStack 2 Underflow!!";
                exit(1);
            }
        }

        void showArray() {
            cout<<"\nArray = ";
            for(int i=0; i<size; i++) {
                cout<<arr[i]<<" ";
            }
        }
};

int main() {
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    ts.showArray();
    cout<<"\nElement popped from Stack 1 = "<<ts.pop1();
    ts.showArray();
    ts.push2(40);
    cout<<"\nElement popped from Stack 2 = "<<ts.pop2();
    ts.showArray();
    return 0;
}