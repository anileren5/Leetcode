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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2){
        TreeNode* new_root = nullptr;
        merge(root1,root2,new_root);
        return new_root;
    }
    
    void merge(TreeNode* root1,TreeNode* root2,TreeNode*& new_root){
        if (root1 != nullptr && root2 != nullptr){
            new_root = new TreeNode(root1->val + root2->val);
            
            if (new_root && root1 && root2 && root1->left != nullptr && root2->left != nullptr) new_root->left = new TreeNode(root1->left->val + root2->left->val);
            else if (new_root && root1 && root2 && root1->left != nullptr && root2->left == nullptr) new_root->left = new TreeNode(root1->left->val);
            else if (new_root && root1 && root2 && root1->left == nullptr && root2->left != nullptr) new_root->left = new TreeNode(root2->left->val);
            
            if (new_root && root1 && root2 && root1->right != nullptr && root2->right != nullptr) new_root->right = new TreeNode(root1->right->val + root2->right->val);
            else if (new_root && root1 && root2 && root1->right != nullptr && root2->right == nullptr) new_root->right = new TreeNode(root1->right->val);
            else if (new_root && root1 && root2 && root1->right == nullptr && root2->right != nullptr) new_root->right = new TreeNode(root2->right->val);
            
            merge(root1->left,root2->left,new_root->left);
            merge(root1->right,root2->right,new_root->right);
            
        }
        else if (root1 != nullptr && root2 == nullptr){
            new_root = new TreeNode(root1->val);
            if (new_root && root1 && root1->left) new_root->left = new TreeNode(root1->left->val);
            if (new_root && root1 && root1->right) new_root->right = new TreeNode(root1->right->val);
            if (root1 && new_root) merge(root1->left,nullptr,new_root->left);
            if (root1 && new_root) merge(root1->right,nullptr,new_root->right);
        }
        else if (root1 == nullptr && root2 != nullptr){
            new_root = new TreeNode(root2->val);
            if (new_root && root2 && root2->left) new_root->left = new TreeNode(root2->left->val);
            if (new_root && root2 && root2->right) new_root->right = new TreeNode(root2->right->val);
            if (root2 && new_root) merge(root2->left,nullptr,new_root->left);
            if (root2 && new_root) merge(root2->right,nullptr,new_root->right);
        }
        else new_root = nullptr;
    }
};   