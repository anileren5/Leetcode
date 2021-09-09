/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    void invert(struct TreeNode* root);
    invert(root);
    return root;
}

void invert(struct TreeNode* root){
    if (root == NULL) return ;
    else{
        struct TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invert(root->left);
        invert(root->right);
    }
}
