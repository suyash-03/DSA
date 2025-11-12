#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

class LinkedList{
    private:
    node* HEAD;
    node* TAIL;

    public:
    LinkedList(){
        HEAD = NULL;
        TAIL = NULL;
    }
    void addNode(int n){
        node* tmp = new node;
        tmp->data = n;
        tmp->next = NULL;
        if(HEAD == NULL){
            HEAD = tmp;
            TAIL = tmp; 
        }
        else if(HEAD != NULL){
            TAIL->next = tmp;
            TAIL = tmp;
        }
    }


    //Iterative Method to Reverse a Linked List
    // prev, current and nextLocal are local variables used to keep a track of links between the elements 

    void reverseLinkedList(){
        node *prev,*current,*nextLocal;
        current = HEAD;
        prev = NULL;
        while (current != NULL)
        {
            nextLocal = current->next;
            current->next = prev;
            prev = current;
            current = nextLocal;
        }
        HEAD = prev;
    }

    void diplayLinkedList(){
        node* tmp;
        tmp = HEAD;
        while(tmp != NULL){
            cout<<tmp->data<<endl;
            tmp = tmp->next;
        }
    }

};


int main(){
    LinkedList linkedList;

    linkedList.addNode(1);
    linkedList.addNode(5);
    linkedList.addNode(9);
    linkedList.addNode(7);
    linkedList.addNode(11);
    linkedList.diplayLinkedList();
    cout<<"Now Displaying reversed Linked List"<<endl;
    linkedList.reverseLinkedList();
    linkedList.diplayLinkedList();
    return 0;
}
