#include<iostream>
#include<stack>
#include<string>
using namespace std;

void printStack(stack<char> s) {
    while(!s.empty()) {
        cout<< s.top() <<endl;
        s.pop();
    }
}

bool isValid(string s) {
    stack<char> st;
    for(char c: s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        }else {
            if(st.empty()) return false;
            if(c == ')' && st.top() == '(' || c == '}' && st.top() == '{' || c == ']' && st.top() == '[') {
                st.pop();
            }else {
                return false;
            }
        }
    }
    printStack(st);
    return st.empty();
}

int main() {
    string s = "(])";
    cout<<isValid(s)<<endl;
    return 0;
}