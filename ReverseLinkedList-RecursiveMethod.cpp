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
    //Function to reverse the linked list using recursion
    void reverseList(node* p) {
       if(p->next == NULL){
           HEAD = p;
           return;
       }
       reverseList(p->next);
       node *q = p->next;
       q->next = p;
       p->next = NULL;
   }

    void print(){
       node *temp = HEAD;
       while (temp != NULL)
       {
           cout<<temp->data<<" ";
           temp = temp->next;
       }
       
   }
};
int main() {
    LinkedList linkedList;
    linkedList.addNode(5);
    linkedList.addNode(6);
    linkedList.addNode(11);
    linkedList.addNode(2);
    linkedList.print();
    cout<<endl;
    linkedList.reverseList(linkedList.HEAD);
    linkedList.print();
    cout<<endl;
}