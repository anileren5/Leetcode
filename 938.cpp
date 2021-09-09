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
    int rangeSumBST(TreeNode* root, int low, int high){
        int sum = 0;
        tree_sum(root,low,high,sum);
        return sum;
    }
    
    void tree_sum(TreeNode* root, int low, int high,int& sum){
        if ((root->val)<=high && (root->val)>=low) sum+=(root->val);
        if (root->right) tree_sum(root->right,low,high,sum);
        if (root->left) tree_sum(root->left,low,high,sum);
    }
};