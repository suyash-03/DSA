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

int isSameTree(BstNode* A, BstNode* B) {
    if(A == NULL && B == NULL){
        return 1;
    }else if(
        A != NULL && B != NULL && A->data == B->data 
        && isSameTree(A->left,B->left)
        && isSameTree(A->right,B->right))
    {
        return 1;
    }
    else{
        return 0;
    }
}



int main(){
    BstNode *root = NULL;
    root = Insert(root,5);
    root = Insert(root,5);
    root = Insert(root,10);
    root = Insert(root,16);

    BstNode *root2 = NULL;
    root2 = Insert(root2,5);
    root2 = Insert(root2,5);
    root2 = Insert(root2,10);
    root = Insert(root2,16);
   

    int result = isSameTree(root,root2);
    cout<<result;

    
    return 0;
}


