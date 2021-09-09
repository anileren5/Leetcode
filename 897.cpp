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
    TreeNode* increasingBST(TreeNode* root) {
        int n = 0; 
        n_nodes(root,n);
        int* stack = new int[n];
        int tracker = 0;
        scan(root,stack,tracker);
        
        TreeNode* pointer_to_new_root = createNode();
        TreeNode* tree_tracker = pointer_to_new_root;
        
        for (int i = 0; i < n; i++){
            TreeNode* new_node = createNode();
            new_node->val = stack[i];
            tree_tracker->right = new_node;
            tree_tracker = tree_tracker->right;
        }
        
        return pointer_to_new_root->right;
    }
    
    void n_nodes(TreeNode* root,int& n){
        if (root) n++;
        if (root->left) n_nodes(root->left,n);
        if (root->right) n_nodes(root->right,n);
    }
    
    void scan(TreeNode* root,int* stack,int& tracker){
        if (root->left) scan(root->left,stack,tracker);
        stack[tracker] = root->val;
        tracker++;
        if (root->right) scan(root->right,stack,tracker);
        
    }
    
    TreeNode* createNode(){
        TreeNode* new_node = new TreeNode;
        new_node->val = -1;
        new_node->left = nullptr;
        new_node->right = nullptr;
        return new_node;
    }
};