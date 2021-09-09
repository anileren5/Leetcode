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
    int sumOfLeftLeaves(TreeNode* root) {
        int accumulator = 0;
        scan(root,accumulator);
        return accumulator;
    }
    
    void scan(TreeNode* root,int& accumulator){
        if (root->left){
            if (is_leaf(root->left)) accumulator += (root->left->val);
        }
        if (root->left) scan(root->left,accumulator);
        if (root->right) scan(root->right,accumulator);
    }
    
    bool is_leaf(TreeNode* node){
        if (node->right == nullptr && node->left == nullptr) return true;
        else return false;
    }
};