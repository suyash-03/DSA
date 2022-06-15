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

int isBalanced(BstNode* A) {
    if(A==NULL){
        return 1;
    }
    int lh = height(A->left);
    int rh = height(A->right);
    
    if(abs(lh-rh)<=1 && isBalanced(A->left) && isBalanced(A->right)){
        return 1;
    }
    return 0;
}


int main(){
    BstNode *root = NULL;
    root = Insert(root,10);
    root = Insert(root,6);
    root = Insert(root,15);
    root = Insert(root,4);
    root = Insert(root,12);
    root = Insert(root,18);
    root = Insert(root,3);
    root = Insert(root,5);
    root = Insert(root,17);
    root = Insert(root,19);
    int data = height(root);
    cout<<"Height: "<<data<<endl;
    int check = isBalanced(root);
    cout<<check;
    
    return 0;
}


