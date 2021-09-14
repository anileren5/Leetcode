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
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> nums;
        vector<int> container;
        scan(root,nums,container);
        int i,j;
        for (i=0;i<nums.size();i++) reverse(nums[i].begin(),nums[i].end());
        int sum = 0;
        for (i=0;i<nums.size();i++){
            int number = 0;
            for (j=0;j<nums[i].size();j++) number += (nums[i][j]*pow(10,j));
            sum += number;
        }
        return sum;
    }
    
    void scan(TreeNode* root,vector<vector<int>>& nums,vector<int> num){
        if (root && root->left == nullptr && root->right == nullptr){
            num.push_back(root->val);
            nums.push_back(num);
        }
        else{
            if (root )num.push_back(root->val);
            if (root->left) scan(root->left,nums,num);
            if (root->right) scan(root->right,nums,num);
        }
    }
};