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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        int level = 0;
        scan(root,result,level);
        reverse(result.begin(),result.end());
        return result;
    }
    
    void scan(TreeNode* root,vector<vector<int>>& result,int level){
        if (root == nullptr) return;
        if (result.size()<=level){
            vector<int> current_level;
            result.push_back(current_level);
        }
        result[level].push_back(root->val);
        if (root->left) scan(root->left,result,level+1);
        if (root->right) scan(root->right,result,level+1);
    }
};