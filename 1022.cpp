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
    int sumRootToLeaf(TreeNode* root) {
        vector<vector<int>> binary_numbers;
        vector<int> empty_container;
        scan(root,binary_numbers,empty_container);
        int sum = 0;
        for (int i=0;i<binary_numbers.size();i++) sum += converter(binary_numbers[i]);
        return sum;
    }
    void scan(TreeNode* root,vector<vector<int>>& binary_numbers,vector<int> binary_number){
        // The number of nodes in the tree is in the range [1, 1000].
        if (root->left == nullptr && root->right == nullptr){
            binary_number.push_back(root->val);
            binary_numbers.push_back(binary_number);
        }
        else{
            binary_number.push_back(root->val);
            if (root->left) scan(root->left,binary_numbers,binary_number);
            if (root->right) scan(root->right,binary_numbers,binary_number);
        }
    }
    
    int converter(vector<int> array){
        int n=0;
        reverse(array.begin(),array.end());
        for (int i=0;i<array.size();i++){
            if (array[i] == 1) n += pow(2,i);
        }
        return n;
    }
};