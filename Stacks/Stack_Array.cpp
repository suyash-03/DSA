#include<stdio.h>
#include<iostream>

#define MAX_SIZE 20
using namespace std;

class Stack{
    private: 
    int A[MAX_SIZE];
    int top = -1;

    public:   
     void Push(int x){
         if(top == MAX_SIZE - 1){
             std::cout<<"Stack Overflow";
             return;
         }
        top = top +1;
        A[top] = x;
    }
    void Pop(){
        if(top == -1){
            std::cout<<"Nothing to Pop";
            return;
        }

        top = top-1;
    }
    bool IsEmpty() {
        if(top == -1){
            std::cout<<true;
            return true;
        }
        else {
            std::cout<<false;
            return false;
        }
    }
    int Top(){
        return A[top];
    }

    void PrintStack(){
        for(int i=0 ;i <=top; i++){
            std::cout << A[i]<<"\n";
        }
    }
};

int main(){
    Stack s1;
    s1.Push(5);
    s1.Push(7);
    s1.Push(9);
    s1.PrintStack();
    s1.Pop();
    s1.PrintStack();
    return 0;

}