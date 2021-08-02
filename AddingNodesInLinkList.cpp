#include <iostream>
#include <stdio.h>
using namespace std;

struct Node{
    int data;
    Node* link;
};

int main(){

    Node* A;
    Node* B;
    B= NULL;
    A = NULL;
    Node* temp = new Node();
    (*temp).data =5;
    (*temp).link = NULL;
    A = temp;
    cout<<A->data<<"\n";
    cout<<A->link<<"\n";
    //First Node Completed

    cout<<"Now Creating a NEW Node \n";
    temp = new Node();
    (*temp).data = 4;
    (*temp).link = NULL;
    B= temp;
    cout<<B->data<<"\n";
    cout<<B->link<<"\n";
    
    return 0;
}