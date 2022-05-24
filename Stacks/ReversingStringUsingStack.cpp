#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<string.h>

#define MAX_SIZE 20

using namespace std;

class Stack{
    private: 
    int A[MAX_SIZE];
    int top = -1;

    public:   
     void Push(char x){
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
    char Top(){
        cout<<char(A[top]);
        return char(A[top]);
    }

    void PrintStack(){
        for(int i=0 ;i <=top; i++){
            std::cout << A[i]<<"\n";
        }
    }
};

void ReverseString(char *c,int length){
    Stack s1;
    Stack s2;
    for(int i=0; i<length; i++){
        s1.Push(c[i]);
    }
    for(int i=0; i<length; i++){
        s2.Push(s1.Top());
        s1.Pop();
    }
}

int main(){
    cout<<"Enter a String \n";
    char str[51];
    gets(str);
    int length = strlen(str);
    ReverseString(str,length);
    return 0;
}