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
