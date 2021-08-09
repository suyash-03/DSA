#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class LinkedList{
    //We need to access HEAD Pointer in main so we are making it public here
    public:
    node* HEAD;
    node* TAIL;
    LinkedList(){
        HEAD = NULL;
        TAIL = NULL;
    }
    void addNode(int n){
        node *temp = new node;
        temp->data = n;
        temp->next = NULL;
        if(HEAD == NULL){
            HEAD = temp;
            TAIL = temp;
        } 
        else if(HEAD != NULL){
            TAIL->next = temp;
            TAIL = temp;
        }
    }
    // Recursion Method to print a Linked List
    void printActual(node* p) {
        if(p == NULL) return;
        cout<<p->data<<" ";
        printActual(p->next);
    }

    // Just interchnage Recursion call and print statement's position
     void printReverse(node* p) {
        if(p == NULL) return;
        printActual(p->next);
        cout<<p->data<<" ";
        
    }
};

int main() {
    LinkedList linkedList;
    linkedList.addNode(5);
    linkedList.addNode(6);
    linkedList.addNode(11);
    linkedList.printActual(linkedList.HEAD);
    cout<<endl;
    linkedList.printReverse(linkedList.HEAD);
}