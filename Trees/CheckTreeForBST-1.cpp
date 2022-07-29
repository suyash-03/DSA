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

bool isSubTreeLesser(BstNode *root,int data){
    if(root == NULL){
        return true;
    }else if(root->data <= data && isSubTreeLesser(root->left,data) && isSubTreeLesser(root->right,data)){
        return true;
    }else{
        return false;
    }
}

bool isSubTreeGreater(BstNode *root,int data){
    if(root == NULL){
        return true;
    }else if(root->data > data && isSubTreeGreater(root->left,data) && isSubTreeGreater(root->right,data)){
        return true;
    }else {
        return false;
    }
};

bool isBinarySearchTree(BstNode *root){
    if(root == NULL){
        return true;
    }else if(
       isSubTreeLesser(root->left,root->data) 
    && isSubTreeGreater(root->right,root->data) 
    && isBinarySearchTree(root->left) 
    && isBinarySearchTree(root->right)){
        return true;
    }else{
        return false;
    }
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
    bool ans = isBinarySearchTree(root);
    cout<<ans;
    return 0;
}


