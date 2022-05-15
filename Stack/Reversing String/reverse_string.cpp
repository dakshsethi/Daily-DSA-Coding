#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

class ST {
    public:
        string revString(string s) {
            stack<char> st;
            for(auto x: s) {
                st.push(x);
            }

            string rev = "";
            while(!st.empty()) {
                rev += st.top();
                st.pop();
            }
            return rev;
        }
};

int main() {
    class ST s1;
    string str = "HelloWorld";
    cout<<"\nReverse String = "<<s1.revString(str);
    return 0;
}