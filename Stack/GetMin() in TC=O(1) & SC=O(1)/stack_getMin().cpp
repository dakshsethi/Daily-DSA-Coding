#include <iostream>
#include <stack>
using namespace std;

class Solution {
    stack<int> st;
    int min;

    public:
        void push(int x) {
            if(st.empty()) {
                st.push(x);
                min = x;
                cout<<x<<" is inserted into stack\t";
            } else if(x < min) {
                int temp = 2*x - min; //this temp value will always be smaller than the current minimum
                st.push(temp);
                min = x;
                cout<<temp<<" is inserted into stack instead of "<<x<<"\t";
            } else {
                st.push(x);
                cout<<x<<" is inserted into stack\t";
            }
            cout<<"Minimum = "<<min<<endl;
        }

        void pop() {
            if(st.empty()) {
                cout<<"Stack is empty\n";
            } else if(st.top() < min) {
                int temp = st.top();
                min = 2*min - temp; //this will update the value of min to previous value;
                cout<<temp<<" is removed from the stack\t";
                cout<<"New Minimum = "<<min<<endl;
                st.pop();
            } else {
                cout<<st.top()<<" is removed from the stack\t";
                cout<<"Minimum = "<<min<<endl;
                st.pop();
            }
        }

        int getMin() {
            return min;
        }
};

int main() {
    class Solution S;
    S.push(5);
    S.push(8);
    S.push(4);
    S.push(3);
    S.push(6);
    S.push(0);
    cout<<"Current Minimum = "<<S.getMin()<<endl;
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    return 0;
}