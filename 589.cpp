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
    vector<int> preorder(Node* root) {
        vector<int> result;
        scan(root,result);
        return result;
    }
    
    void scan(Node* root,vector<int>& result){
        if (root == nullptr) return;
        result.push_back(root->val);
        for (int i=0;i<(root->children).size();i++) if ((root->children)[i]) scan(root->children[i],result);
    }
};