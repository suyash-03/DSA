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

    void createCycle(int index){
        //index here refers to the which index element of the linked list a cycle would be created
        Node *temp = new Node;
        Node *temp2 = new Node;
        temp = temp2 = HEAD;
        while(temp->next != NULL){
            temp = temp->next;
        }
        for(int i = 0 ; i< index; i++){
            temp2 = temp2->next;
        }
        temp->next = temp2;
    }

    bool hasCycle() {
        //0(1) space & o(n) time
        Node *fast, *slow;
        fast = HEAD;
        slow = HEAD;
        while(slow != NULL && fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            } 
        }
        return false;
    }
};

int main(){
    LinkedList l1;
    l1.addNode(3);
    l1.addNode(2);
    l1.addNode(0);
    l1.addNode(-4);
    l1.createCycle(1);
    bool result = l1.hasCycle();
    cout<<result;
    return 0;
}