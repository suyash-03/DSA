#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {	
public:
    int max_path_sum = INT_MIN;
    int maxPathSumUtil(TreeNode * root){
        if(root == NULL){
            return 0;
        }
        int leftSum = max(0, maxPathSumUtil(root->left));
        int rightSum = max(0, maxPathSumUtil(root->right));

        // Track the Global Maximum at Root Level
        max_path_sum = max(max_path_sum, root->data + leftSum + rightSum);
        return root->data + max(leftSum,rightSum);

    }
    int maxPathSum(TreeNode* root) {
        maxPathSumUtil(root);
        return max_path_sum;
    }
};	

int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Maximum Path Sum: " << s.maxPathSum(root) << endl;
    
    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}   