//Better way to do this will be to put all the opening paranthesis in a stack and keep checking for
//closing paranthesis if it's of the same type we can pop from the stack else it's not balanced
//at the end of the process if the stack is empty there are balanced paranthesis

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.size() == 0) return true;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(s[i] == ')' && !st.empty() && st.top() == '('){
                    st.pop();
                }else if(s[i] == '}' && !st.empty() && st.top() == '{'){
                    st.pop();
                }else if(s[i] == ']' && !st.empty() && st.top() == '['){
                    st.pop();
                }else{
                    return false;
                }
            }
        }

        if(st.empty()) return true;
        return false;
    }
};