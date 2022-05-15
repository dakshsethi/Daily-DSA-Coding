#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto x: s) {
            if(x=='(' || x=='{' || x=='[' || st.empty())
                st.push(x);
            else {
                if(x == ')' && st.top() == '(')
                    st.pop();
                else if(x == '}' && st.top() == '{')
                    st.pop();
                else if(x == ']' && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
        if (st.empty()) { 
            return true;
        }
        else
            return false;
    }
};

int main() {
    class Solution Sol;
    string s = "(()){}";
    cout<<"\nValidity: "<<Sol.isValid(s);
    return 0;
}