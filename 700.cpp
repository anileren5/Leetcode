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
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val){
        TreeNode* subtree = nullptr;
        search_tree(root,val,&subtree);
        return subtree;
    }
    
    void search_tree(TreeNode* root,int val,TreeNode** psubtree){
        if (root->val == val) *(psubtree) = root;
        if (root->left != nullptr) search_tree(root->left,val,psubtree);
        if (root->right != nullptr) search_tree(root->right,val,psubtree);
    }
};