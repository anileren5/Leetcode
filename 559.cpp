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
    int maxDepth(Node* root) {
        vector<int> depths;
        scan(root,depths,1);
        if (depths.size() == 0) return 0;
        else {
            int max_depth = 0;
            for (int i=0;i<depths.size();i++) if (depths[i] > max_depth) max_depth = depths[i];
            return max_depth;
        }
    }
    
    void scan(Node* root,vector<int>& depths,int depth){
        if (root == nullptr) return;
        if (root->children.size() == 0) depths.push_back(depth);
        else{
            for(int i=0;i<root->children.size();i++){
               scan(root->children[i],depths,depth+1); 
            }
        }
    } 
};