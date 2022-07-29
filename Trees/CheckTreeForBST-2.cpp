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



bool isBinarySearchTree(BstNode *root,int minValue,int maxValue){
    if(root == NULL){
        return true;
    }else if(
       root->data < maxValue && root->data > minValue
    && isBinarySearchTree(root->left,minValue,root->data) 
    && isBinarySearchTree(root->right,root->data,maxValue)){
        return true;
    }else{
        return false;
    }
}



int main(){
    BstNode *root = NULL;
    root = Insert(root,2);
    root = Insert(root,1);
    root = Insert(root,3);
    //INT_MIN && INT_MAX are macros for maximum and minimum integer values
    bool ans = isBinarySearchTree(root,INT_MIN,INT_MAX);
    cout<<ans;
    return 0;
}


