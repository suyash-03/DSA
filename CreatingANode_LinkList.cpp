#include <iostream>
#include <stdio.h>
using namespace std;

struct Node{
    int data;
    Node* link;
};

int main(){

    Node* A;
    A = NULL;
    Node* temp = (Node*) malloc(sizeof(Node));
    // Node* temp = new Node() can also be used
    (*temp).data =5;
    (*temp).link = NULL;
    A = temp;
    cout<<A->data<<"\n";
    // 0 Pointer refers to pointer pointing to null
    cout<<A->link;
    return 0;
}