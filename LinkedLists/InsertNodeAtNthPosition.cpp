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

    void addNodeAtNthPosition(int data , int position){
        node* tmp1 = new node;
        tmp1->data = data;
        tmp1->next = NULL;
        if (position ==1 ){
            tmp1->next = HEAD;
            HEAD = tmp1;
        }
        else if(position != 1){
            node *tmp2 = HEAD;
            for(int i = 0 ; i< position-2; i++){
                tmp2 = tmp2->next;
            }
            tmp1->next = tmp2->next;
            tmp2->next = tmp1;
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
    linkedList.addNodeAtNthPosition(2,2);
    linkedList.diplayLinkedList();
    return 0;
}
