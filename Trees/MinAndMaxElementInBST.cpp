#include<iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode* getNewNode(int data){
    BstNode *temp = new BstNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) {
		root = getNewNode(data);
	}
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

//  Root here acts as local variable and modifying it won't change the root in main function
int minElement(BstNode *root){
    if(root == NULL){
        cout<<"The tree is empty";
        return -1;
    }
    while (root->left != NULL){
        root = root->left;
    }
    cout<<"The Minimum Element in tree is: "<<root->data<<endl;
    return root->data;
}

int minElementRecursion(BstNode *root){
    if(root == NULL){
        cout<<"The tree is empty";
        return -1;
    }
    if(root->left == NULL){
        cout<<"The Minimum Element in tree is: "<<root->data<<endl;
        return root->data;
    }
    return minElementRecursion(root->left);
}

int maxElement(BstNode *root){
    if(root == NULL){
        cout<<"The tree is empty";
        return -1;
    }
    while(root->right != NULL){
        root = root->right;
    }
    cout<<"The Maximum Element in the tree is: "<<root->data<<endl;
    return root->data;
}

int main(){
    BstNode *root = NULL;
    root = Insert(root,10);
    root = Insert(root,8);
    root = Insert(root,15);
    root = Insert(root,6);
    root = Insert(root,9);
    root = Insert(root,12);
    root = Insert(root,18);
    int min = minElement(root);
    int minRecursion = minElementRecursion(root);
    return 0;
}


