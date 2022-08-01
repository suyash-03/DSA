// Binary Search Tree - Implemenation in C++
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};

// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node 
BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

// We need to return a list of list of all elements in a level of a Binary Tree
vector<vector<int>> levelOrder(BstNode* root) {
    vector<vector<int>> result;
    queue<BstNode*> q1;
    q1.push(root);
    while( !q1.empty() ){
        int len = q1.size();
        vector<int> r = {};
        for(int i=0 ; i<len; i++){
            BstNode* current = q1.front();
            if(current != NULL){
                r.push_back(current->data);
                if(current->left != NULL){
                    q1.push(current->left);
                }
                if(current->right != NULL){
                    q1.push(current->right);
                }
            }
        q1.pop();
    }
    if(!r.empty()) result.push_back(r);
    }
    return result;       
}
            
  


int main() {
    vector<vector<int>> result;
	BstNode* root = NULL;  // Creating an empty tree
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
   

    result = levelOrder(root);
    
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
    }