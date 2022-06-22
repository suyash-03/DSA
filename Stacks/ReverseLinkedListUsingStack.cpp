#include<iostream>
#include<stack>
#include<stdio.h>

using namespace std;

struct node{
    int data;
    node* next;
};

class linked_list
{  
public:
    node *head,*tail;
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    //Add a node at the end of the linked list
    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            // tail = tail->next;
            tail = tmp;
        }
    }
    void add_node_beginning(int n){
        node* tmp = new node;
        tmp->data = n;
        tmp->next = head;
        head = tmp;
    }

    //Traversing through the List
    void display()
    {
        node *tmp;
        tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data<<"-";
            tmp = tmp->next;
        }
        cout<<"\n";
    }
};

void ReverseLinkedListUsingStack(linked_list l1){
    stack<struct node*> s1;
    node* temp;
    temp = l1.head;
    if(l1.head == NULL){
        return;
    }else{
        while(temp != NULL){
            s1.push(temp);
            temp = temp->next;
        }
        temp = s1.top();
        l1.head = temp;
        s1.pop();
        while(!s1.empty()){
           temp->next = s1.top();
           s1.pop();
           temp = temp->next;
        }
        temp->next = NULL;

        cout<<"The list after Reversal is: \n";
        node* temp2;
        temp2 = l1.head;
        while(temp2 != NULL){
            cout<<temp2->data<<"-";
            temp2 = temp2->next;
        }
    }
}

int main(){
    linked_list l1;
    l1.add_node(5);
    l1.add_node(6);
    l1.add_node(7);
    l1.display();
    ReverseLinkedListUsingStack(l1);
    return 0;
}