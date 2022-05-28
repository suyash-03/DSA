#include<iostream>
#include<stdio.h>
#define MAX_SIZE 5 //maximum size of the array that will store Queue. 

using namespace std;    

/*To use the lefover cells after dequeue operation we use the circular implementation of the array
In circular array if current position is 'i' then next position is given by (i+1)%N where N is the size of the array 
likewise the previous position is given (i + (N-1))%N */

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
        int N = MAX_SIZE;
        if((rear+1)%N == front){
            cout<<"Queue is full \n";
            return;
        }
        else if(isEmpty()){
            rear = 0;
            front = 0;
        }else {
            rear = (rear + 1)%N;
        }
        A[rear] = x;
    }
    void dequeue(){
        int N = MAX_SIZE;
        if(isEmpty()){
            cout<<"Queue is empty \n";
            return;
        } else if (rear == front){
            //Basically there's just one element in the queue
            front = -1;
            rear = -1;
        } else {
            front = (front + 1)%N;
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
    q1.enqueue(2);
    q1.dequeue();
    q1.enqueue(0);
    q1.enqueue(6);
    q1.Peek();
    return 0;
}