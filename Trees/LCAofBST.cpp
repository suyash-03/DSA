/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Lowest Common Ancestor of Binary Search Tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* current = root;
        
        while(current != NULL){
            if(current->val < p->val && current->val < q->val){
                current = current->right;
            }else if(current->val > p->val && current->val > q->val){
                current = current->left;
            }else{
                return current;
            }
        }
        return current;
    }
};
