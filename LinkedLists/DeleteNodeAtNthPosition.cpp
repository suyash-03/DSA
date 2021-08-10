#include <iostream>
#include<conio.h>
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

    //n here denotes position of element in the list
    void deleteNodeAtNthPosition(int n){
        node* temp1 = HEAD;
        if(n==1){
            HEAD = temp1->next;
            delete(temp1);
        }else {
            for(int i=0 ; i<n-2 ; i++ ){
                temp1 = temp1->next;  //Reached (n-1)th node
            }
            node* temp2 = temp1->next; //Reached nth node or the node to be deleted
            temp1->next = temp2->next;
            delete(temp2);
        }
    }

    //Printing the List
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
    linkedList.diplayLinkedList(); //1,5,9
    cout<<"Deleting Item at Second Position: New List -> "<<endl;
    linkedList.deleteNodeAtNthPosition(2); //1,9
    linkedList.diplayLinkedList();
    return 0;
}
