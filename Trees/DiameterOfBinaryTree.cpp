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
    int heightOfTree(TreeNode *root){
        if(root == NULL){
            return -1;
        }
        return 1+max(heightOfTree(root->left),heightOfTree(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int diameter = heightOfTree(root->left) + heightOfTree(root->right)+2;
        return max(diameter,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));

    }
};
