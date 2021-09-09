/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    void helper(struct TreeNode* p, struct TreeNode* q, bool* flag);
    bool result = true;
    helper(p,q,&result);
    return result;
}

void helper(struct TreeNode* p, struct TreeNode* q, bool* flag){
    if (p == NULL && q == NULL) return 0;
    else if (p == NULL && q != NULL){
        *flag = false;
        return ;
    }
    
    else if (p != NULL && q == NULL){
        *flag = false;
        return ;
    }
    
    else if (p->val != q->val){
        *flag = false;
        return;
    }
    
    helper(p->left,q->left,flag);
    helper(p->right,q->right,flag);    
}