#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};

class DoublyLinkedList{
    public:
    node* HEAD;
    DoublyLinkedList(){
        HEAD = NULL;
    }
     // Creates a new node in the heap section of the memory 
     // and returns a Pointer to the newly created node 

    node* getNewNode(int x){
        node *  newNode = new node;
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }
    void insertAtHead(int n){
        node *temp = getNewNode(n);
        if(HEAD == NULL){
            HEAD = temp;
        }
        else if (HEAD != NULL){
            HEAD->prev = temp;
            temp->next = HEAD;
            HEAD = temp;
            }
    }
    void insertAtTail(int n){
        node *temp = getNewNode(n);
        if(HEAD == NULL){
            HEAD = temp;
        } else if (HEAD != NULL){
            node *temp2;
            temp2 = HEAD;
            //Getting to the last node of the list
            while(temp2->next != NULL){
                temp2 = temp2->next;
            }
            // Now Changing the Links
            temp2->next = temp;
            temp->prev = temp2;
        }
    }

    //Forward Direction
    void printList(){
        node *temp = HEAD;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    //Backward Direction
    void printListBackwards(){
        node *temp = HEAD;
        
        //Return if List is empty
        if(temp == NULL) return; 
        
        //Reaching the end of the List
        while(temp->next !=NULL){
            temp = temp->next;
            }  
            node *TAIL = temp;
            while (TAIL != NULL)
            {
                cout<<TAIL->data<<" ";
                TAIL = TAIL->prev;
            }
        }
};
int main(){
    DoublyLinkedList doublyLinkedList;
    doublyLinkedList.insertAtTail(1);
    doublyLinkedList.insertAtTail(2);
    doublyLinkedList.insertAtTail(3);
    doublyLinkedList.insertAtHead(0);
    doublyLinkedList.printList();
    cout<<endl;
    doublyLinkedList.printListBackwards();
}