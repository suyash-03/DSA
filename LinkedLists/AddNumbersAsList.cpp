#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class LinkedList{
    public:
    node* HEAD;
    node* TAIL;
    LinkedList(){
        HEAD =  NULL;
        TAIL = NULL;
    };

    void addNode(int x){
        node* temp = new node;
        temp->data = x;
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
    node* reverseLinkedList(node* A){
        node *current, *prev, *nextLocal;
        current = A;
        prev = NULL;
        nextLocal = A->next;
        while(current != NULL){
            nextLocal = current->next;
            current->next = prev;
            prev = current;
            current = nextLocal;
        }
        return prev;
    }

    void print(node* A){
       node *temp = A;
       while (temp != NULL)
       {
           cout<<temp->data<<" ";
           temp = temp->next;
       }
       
   }

    void addTwoListsAsNumber(node *first,node *second){
        LinkedList newList;
        node *fr, *sr;
        fr = reverseLinkedList(first);
        sr = reverseLinkedList(second);

        while(fr != NULL && sr != NULL){
            if((fr->data+sr->data)>=10){
                newList.addNode((fr->data+sr->data)%10);
                fr = fr->next;
                sr = sr->next;
                if(fr->data != NULL && sr->data != NULL){
                    fr->data = fr->data + 1;
                } else if (fr->data != NULL && sr->data == NULL){
                     fr->data = fr->data + 1;
                } else if (fr->data == NULL && sr->data != NULL){
                    sr->data = sr->data + 1;
                }
            } else {
                newList.addNode((fr->data+sr->data));
                fr = fr->next;
                sr = sr->next;
            }
        }
        if(fr != NULL){
            while(fr != NULL){
                newList.addNode(fr->data);
                fr = fr->next;
            }
        }
        else if (sr != NULL){
            while(sr != NULL){
                newList.addNode(sr->data);
                sr = sr->next;
            }
        }

        node *result;
        result = reverseLinkedList(newList.HEAD);
        print(result);
    }

int main(){
    LinkedList first;
    LinkedList second;
    first.addNode(1);
    first.addNode(2);
    first.addNode(5);
    second.addNode(1);
    second.addNode(3);
    second.addNode(5);
    second.addNode(0);
    addTwoListsAsNumber(first.HEAD,second.HEAD);
    return 0;
}