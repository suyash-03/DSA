#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    public:
    Node* HEAD;
    Node* TAIL;
    LinkedList(){
        HEAD = NULL;
        TAIL = NULL;
    }

    void addNode(int data){
        Node* temp = new Node;
        temp->data = data;
        temp->next = NULL;
        if(HEAD == NULL){
            HEAD = temp;
            TAIL = temp;
        } else {
            TAIL->next = temp;
            TAIL = temp;
        }
    }
};


void mergeTwoLists(Node* list1, Node* list2) {
    Node *dummy, *temp;
    dummy = new Node;
    temp = dummy;
        
        //when both list1 and list2 isn't empty
    while(list1 && list2){
            if(list1->data < list2->data){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;   
            }
            temp = temp->next;
        }
        
        // we reached at the end of one of the list
        if(list1) temp->next = list1;
        if(list2) temp->next = list2;
        
        while (dummy->next != NULL)
        {
            cout<<dummy->next->data<<" ";
            dummy->next = dummy->next->next;
        }
    }


int main(){
    LinkedList l1,l2,l3;
    l1.addNode(3); l2.addNode(0);
    l1.addNode(4); l2.addNode(4);
    l1.addNode(6); l2.addNode(8);
    l1.addNode(7); l2.addNode(9);
    mergeTwoLists(l1.HEAD,l2.HEAD);
    return 0;
}