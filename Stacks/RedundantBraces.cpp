#include<cstring>
#include<stack>
#include<string>
#include<iostream>
using namespace std;

int braces(string A) {
    stack<char> s1;
    for(int i=0; i<A.length(); i++){
        if(A[i] == '(' || A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/'){
            s1.push(A[i]);
        } 
    }
    while(!s1.empty()){
        if(s1.top() == '+' || s1.top() == '-' || s1.top() == '*' || s1.top() == '/' ){
            if(!s1.empty()) s1.pop();
            if(!s1.empty()) s1.pop();
        } else{
            return 1;
        }
    }
    if(s1.empty()){
        return 0;
    }else{
        return 1;
    }
    
}

int main(){
    string str = "(a+(a+b))";
    int data = braces(str);
    cout<<data;
    return 0;
}
