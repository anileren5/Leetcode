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
    int maxDepth(TreeNode* root) {
        vector<int> depths;
        int max_depth = 0;
        scan(root,depths,1);
        if (depths.size() == 0) max_depth = 0;
        else for (int i=0;i<depths.size();i++) if (depths[i] > max_depth) max_depth = depths[i];
        return max_depth;
    }
    
    void scan(TreeNode* root,vector<int>& depths,int depth){
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) depths.push_back(depth);
        if (root->left) scan(root->left,depths,depth+1);
        if (root->right) scan(root->right,depths,depth+1);
    }
};