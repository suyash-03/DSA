#include<iostream>
#include<stdio.h>
#define MAX_SIZE 10 //maximum size of the array that will store Queue. 

using namespace std;    

class Queue{

    private:
    int front;
    int rear;

    public:
    Queue(){
        front = -1;
        rear = -1;
    }

    int A[MAX_SIZE];

    bool isEmpty(){
        if(rear == -1 && front == -1){
            return true;
        }else {
            return false;
        }
    }

    void enqueue(int x){
        if(rear == sizeof(A)-1){
            cout<<"Queue is full \n";
            return;
        }
        else if(isEmpty()){
            rear = 0;
            front = 0;
        }else {
            rear = rear + 1;
        }
        A[rear] = x;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty \n";
            return;
        } else if (rear == front){
            //Basically there's just one element in the queue
            front = -1;
            rear = -1;
        } else {
            front = front + 1;
        }
    }

    int Peek(){
        cout<<A[front];
        return A[front];
    }
};

int main(){
    Queue q1;
    q1.enqueue(5);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.Peek();
    return 0;
}