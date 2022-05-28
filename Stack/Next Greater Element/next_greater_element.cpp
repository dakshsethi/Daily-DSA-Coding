#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        vector<long long> nextGreaterElement(vector<long long> arr, int n) {
            vector<long long> nge(n, -1);
            stack<int> st;
            for(int i=0; i<n; i++) {
                while(!st.empty() && arr[st.top()] < arr[i]) {
                    nge[st.top()] = arr[i];
                    st.pop();
                }
                st.push(i);
            }
            return nge;
        }

        void printArray(vector<long long> arr, int n) {
            for(int i=0; i<n; i++)
                cout<<arr[i]<<" ";
        }
};

int main() {
    class Solution S;
    vector<long long> arr = {1,2,3,4,5};
    int n = arr.size();
    vector<long long> nge = S.nextGreaterElement(arr, n);

    cout<<"Original Array: ";
    S.printArray(arr, n);
    cout<<"\nNext Greater Element Array: ";
    S.printArray(nge, n);
}