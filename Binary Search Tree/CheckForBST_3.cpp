#include<iostream>
#include<vector>
using namespace std;
vector<int> temp;

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

void inOrderTraversal(BstNode *root){
    if(root == NULL){
        return;
    }else{
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        temp.push_back(root->data);
        inOrderTraversal(root->right);
    }
}


bool isBinarySearchTree(BstNode *root){
    if(root == NULL){
        return true;
    }else{
        vector<int> vec1;
        inOrderTraversal(root);
        for(int i=0;i<temp.size()-1; i++){
            if(temp[i]>temp[i+1]){
                return false;
            }
        }
        return true;
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
    cout<<"\n";
    cout<<ans;
    return 0;
}


