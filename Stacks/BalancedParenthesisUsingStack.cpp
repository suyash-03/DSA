//Better way to do this will be to put all the opening paranthesis in a stack and keep checking for
//closing paranthesis if it's of the same type we can pop from the stack else it's not balanced
//at the end of the process if the stack is empty there are balanced paranthesis

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>

using namespace std;

void checkForBalancedParanthesis(char *c,int length){
    stack<char> s_open;
    stack<char> s_close;
    stack<char> s_close_reverse;
    for(int i=0; i<length; i++){
        if(c[i] == '[' || c[i] == '{' ||c[i] == '('){
            s_open.push(c[i]);
        } else if (c[i] == ']' || c[i] == '}' ||c[i] == ')'){
            s_close.push(c[i]);
        }
    }
   
    //Reversing s_close stack
    int len = s_close.size();
    for(int i=0 ; i < len; i++){
        s_close_reverse.push(s_close.top());
        s_close.pop();
    }
    
    if(s_open.size() == s_close_reverse.size()){
        int len2 = s_open.size();
        for(int i=0 ;i < len2; i++){
            if(s_open.top() == '[' && s_close_reverse.top() != ']'){
                cout<<"Not Balanced Paranthesis \n";
                return;
            }
            if(s_open.top() == '{' && s_close_reverse.top() != '}'){
                cout<<"Not Balanced Paranthesis \n";
                return;
            }
            if(s_open.top() == '(' && s_close_reverse.top() != ')'){
                cout<<"Not Balanced Paranthesis \n";
                return;
            }
            s_open.pop();
            s_close_reverse.pop();
        }
        cout<<"Balanced Paranthesis \n";
    } else {
        cout<<"Not Balanced Paranthesis \n";
        return;
    }
}

int main(){
    cout<<"Enter a String to check for balanced paranthesis \n";
    char str[50];
    gets(str);
    int length = strlen(str);
    checkForBalancedParanthesis(str,length);
    return 0;
}