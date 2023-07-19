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

//Striver
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left == NULL){
            return right;
        }else if(right == NULL){
            return left;
        }else{
            return root;
        }
    }
};
