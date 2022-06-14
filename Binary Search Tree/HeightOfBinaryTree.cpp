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
int height(BstNode *root){
    if(root == NULL){
        return -1;
    }else{
        return max(height(root->left),height(root->right))+1;
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
    int data = height(root);
    cout<<"Height: "<<data;
    
    return 0;
}


