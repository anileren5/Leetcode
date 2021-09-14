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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<vector<int>> targetPaths;
            vector<int> container;
            scan(root,targetPaths,container,targetSum);
            return targetPaths;
    }
    
    int pathSum(vector<int> path){
        int i,sum = 0;
        for (i=0;i<path.size();i++) sum += path[i];
        return sum;
    }
    
    void scan(TreeNode* root,vector<vector<int>>& targetPaths,vector<int> container,int targetSum){
        if (root && root->left == nullptr && root->right == nullptr){
            container.push_back(root->val);
            if (pathSum(container) == targetSum) targetPaths.push_back(container);
        }
        else{
            if (root) container.push_back(root->val);
            if (root && root->left) scan(root->left,targetPaths,container,targetSum);
            if (root && root->right) scan(root->right,targetPaths,container,targetSum);
        }
    }
    
    
};