#include<iostream>
#include<stdio.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedListQueue{
    public:
    Node* front;
    Node* rear;

    LinkedListQueue(){
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x){
        Node* temp = new Node;
        temp->data = x;
        temp->next =  NULL;
        if(front == NULL && rear == NULL){
            front = temp;
            rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue(){
        Node* temp = front;
        if(front == NULL){
            return;
        } 
        if(front == rear){
            front = NULL;
            rear = NULL;
        }else{
            front = front->next;
        }
        free(temp);
    }

    void Peek(){
        cout<<front->data<<"\n";
    }
};

int main(){
        LinkedListQueue lq1;
        lq1.enqueue(5);
        lq1.enqueue(6);
        lq1.dequeue();
        lq1.enqueue(7);
        lq1.Peek();
        return 0;
}