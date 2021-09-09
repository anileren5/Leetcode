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
    bool isUnivalTree(TreeNode* root){
        bool result = true;
        scan(root,result);
        return result;
    }
    
    void scan(TreeNode* root,bool& result){
        if (root->right != nullptr && root->left != nullptr){
            int v_root = root->val;
            int v_right = root->right->val;
            int v_left = root->left->val;
            if (v_root == v_left && v_root == v_right && v_left == v_right) ;
            else result = false;
        }
        
        else if (root->right == nullptr && root->left != nullptr){
            int v_root = root->val;
            int v_left = root->left->val;
            if (v_root == v_left) ;
            else result = false;
        }
        
        else if (root->right != nullptr && root->left == nullptr){
            int v_root = root->val;
            int v_right = root->right->val;
            if (v_root == v_right) ;
            else result = false;
        }
        
        if (root->right) scan(root->right,result);
        if (root->left) scan(root->left,result);
    }
};