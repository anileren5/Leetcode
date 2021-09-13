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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        scan(root1,leaves1);
        scan(root2,leaves2);
        bool flag = true;
        int boundary = (leaves1.size() >= leaves2.size()) ? leaves2.size() : leaves1.size();
        if (leaves1.size() != leaves2.size()) return false;
        else for (int i=0;i<boundary;i++) if (leaves1[i] != leaves2[i]) {flag = false;break;}
        return flag;
    }
    
    void scan(TreeNode* root,vector<int>& leaves){
        if (root->left != nullptr) scan(root->left,leaves);
        if (root->left == nullptr && root->right == nullptr) leaves.push_back(root->val);
        if (root->right != nullptr) scan(root->right,leaves);
    }
};