/*
Time complexity - 0(n) in all cases
Space Complexity - 0(n) average case (0(1) best, O(N) worst)
*/
#include<iostream>
#include<queue>
using namespace std;

struct BstNode {
	char data; 
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
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

// We will use STL queue
// Time and Space complexity: O(n)
void levelOrderTraversal(BstNode *root){
    if(root == NULL){
        return;
    }
    queue<BstNode*> q;
    q.push(root);
    while( !q.empty() ){
        BstNode* current = q.front();
        cout<<current->data<<" ";
        if(current->left != NULL){
            q.push(current->left);
        }
        if(current->right != NULL){
            q.push(current->right);
        }
        q.pop();  //removing the element at first
    }
}

int main() {
	BstNode* root = NULL;  // Creating an empty tree
	root = Insert(root,'F');	
	root = Insert(root,'D');	
	root = Insert(root,'J');
	root = Insert(root,'B');
	root = Insert(root,'E');
	root = Insert(root,'G');
    levelOrderTraversal(root);
	
}
