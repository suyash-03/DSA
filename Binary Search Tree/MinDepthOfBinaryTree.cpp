/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            int n = q.size();
            count = count + 1;
            for(int i=0;i<n; i++){
                TreeNode *front = q.front();
                if(front->left == NULL && front->right == NULL){
                    return count;
                }
                if(front->left != NULL){
                    q.push(front->left);
                }
                if(front->right != NULL){
                    q.push(front->right);
                }
                q.pop();
            }
        }
        return count;
}
