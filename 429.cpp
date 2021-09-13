/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        int level = 0;
        scan(root,result,level);
        return result;
    }
    
    void scan(Node* root,vector<vector<int>>& result,int level){
        if (root == nullptr) return;
        if (result.size()<=level){
            vector<int> current_level;
            result.push_back(current_level);
        }
        result[level].push_back(root->val);
        for (int i=0;i<(root->children).size();i++) if ((root->children)[i]) scan((root->children)[i],result,level+1);
    }
};