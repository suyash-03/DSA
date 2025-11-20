#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetricUtil(TreeNode *leftNode, TreeNode *rightNode){
        if(leftNode == NULL && rightNode == NULL){
            return true;
        }else if((leftNode == NULL && rightNode != NULL) || (leftNode != NULL && rightNode == NULL)){
            return false;
        }else if(leftNode->val == rightNode->val && isSymmetricUtil(leftNode->left,rightNode->right) && isSymmetricUtil(leftNode->right, rightNode->left)){
            return true;
        }else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return isSymmetricUtil(root->left, root->right);
    }
};