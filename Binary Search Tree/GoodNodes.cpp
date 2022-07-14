/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
    a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
 */
class Solution {
public:
    vector<int> nodes;
    int count = 0;
    void preOrderTraversal(TreeNode* root,int maxValue){
        if(root == NULL){
            return;
        }
        if(root->val < maxValue){
            count++;
        }
        if(root->val > maxValue){
            maxValue = root->val;
        }
        nodes.push_back(root->val);
        preOrderTraversal(root->left,maxValue);
        preOrderTraversal(root->right,maxValue);
    }
        
    int goodNodes(TreeNode* root) {
        preOrderTraversal(root,root->val);
        return nodes.size()-count;
    }
};
