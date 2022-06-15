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

/* Space complexity of all DFS algorithms
   will be O(h) {
    Worst: 0(n)
    Average: 0(logn)
   } 

   Time complexity of all DFS algorithms 
   will be 0(n)
*/

void preOrderTraversal(BstNode *root){
    if(root ==  NULL){
        return;
    }else{
        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(BstNode *root){
    if(root == NULL){
        return;
    }else{
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(BstNode *root){
    if(root == NULL){
        return;
    }else{
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" ";
    }
}



int main(){
    BstNode *root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,12);
    root = Insert(root,17);
    root = Insert(root,25);
    preOrderTraversal(root);
    cout<<"\n";
    inOrderTraversal(root);
    cout<<"\n";
    postOrderTraversal(root);
    return 0;
}


