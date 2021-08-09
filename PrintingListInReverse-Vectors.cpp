#include <iostream>
#include <vector>
using namespace std;

struct node{
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
    // Used vectors to create an array and then print it in reverse order
    void printListReverse(){
        node *temp ;
        temp = HEAD;
        vector<int> vec1;
        while(temp != NULL){
            vec1.push_back(temp->data);
            temp = temp->next;
        }
        int length = vec1.size();
        for(int i = length-1 ;i >= 0 ; i--){
            cout<<vec1[i]<<" ";
        }
    }
};

int main() {
    LinkedList linkedList;
    linkedList.addNode(5);
    linkedList.addNode(6);
    linkedList.addNode(11);
    linkedList.printListReverse();
}