#include<stdio.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

//LINKED list implementation of Stack
class LinkedList{
    private:
    Node* HEAD;
    Node* TAIL;
    public:
    LinkedList(){
        HEAD = NULL;
        TAIL = NULL;
    }

    void Push(int x){
        Node* temp = new Node;
        if(HEAD == NULL){
            HEAD = temp;
            temp->data = x;
            temp->next = NULL;
            TAIL = temp;        
        } else {
           temp->data = x;
           temp->next = HEAD;
           HEAD = temp; 
        }
    }
    void Pop(){
        if(HEAD != NULL){
            Node* temp = new Node;
            temp = HEAD;
            HEAD = HEAD->next;
            delete(temp);
            }
        else{
            cout<<"The STACK is empty: Nothing to POP"<<endl;
        }
    }
    void Top(){
        cout<<HEAD->data;
    }
    void PrintStack(){
        Node* temp = new Node;
        temp = HEAD;
        while(temp!= NULL){
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
    }

};

int main(){
    LinkedList linkedList;
    linkedList.Push(5);
    linkedList.Push(7);
    linkedList.Push(8);
    linkedList.PrintStack();
    cout<<"\n";
    linkedList.Top();
    return 0;
}