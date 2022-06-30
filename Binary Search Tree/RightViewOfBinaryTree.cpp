#include<iostream>
#include<vector>
#include<queue>

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

    vector<int> rightSideView(BstNode* root) {
        vector<int> result;
        queue<BstNode*> q;
        if(root == NULL) return result;
        q.push(root);

        while( !q.empty() ){
            int n = q.size();
            //Loop Conditions are Determined before the loop starts running it won't change if loop variables are changed inside the loop
            for(int i=0; i<n; i++){
                BstNode* frontNode = q.front();
                if(i == n-1){
                    result.push_back(frontNode->data);
                }
                if(frontNode->left != NULL){
                    q.push(frontNode->left);
                }
                if(frontNode->right != NULL){
                    q.push(frontNode->right);
                }
                q.pop();
            }
        }
        return result;
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

    vector<int> result = rightSideView(root);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    
    return 0;
}


