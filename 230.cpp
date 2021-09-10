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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> array;
        scan(root,array);
        return array[k-1];
    }
    
    void scan(TreeNode* root,vector<int>& array){
        if (root->left) scan(root->left,array);
        array.push_back(root->val);
        if (root->right) scan(root->right,array);
    }
};