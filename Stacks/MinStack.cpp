#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int value) pushes the element value onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/

class MinStack {
public:
    stack<int> st1;
    stack<int> st2;
    MinStack() {
        st1 = {};
        st2 = {};
    }
    
    void push(int value) {
        st1.push(value);
        if(st2.empty() || value <= st2.top()){
            st2.push(value);
        }
    }
    
    void pop() {
        if(st1.top() == st2.top()){
            st1.pop();
            st2.pop();
        }else{
            st1.pop();
        }
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */