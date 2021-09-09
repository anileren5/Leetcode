/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *path1,*path2,*head,*tracker;
    if (l1 == NULL && l2 == NULL) return NULL;
    if (l1 == NULL && l2 != NULL) return l2;
    if (l2 == NULL && l1 != NULL) return l1;
    if (l1->val <= l2->val){
        head = l1;
        tracker =  l1;
        path1 = l1->next;
        path2 = l2;
        while (!(path1 == NULL && path2 == NULL)){
            if (path1 == NULL && path2 != NULL){
                tracker->next = path2;
                path2 = path2->next;
                tracker = tracker->next;
            }
            
            else if (path1 != NULL && path2 == NULL){
                tracker->next = path1;
                path1 = path1->next;
                tracker = tracker->next;
            }
            
            else if (path1->val <= path2->val){
                tracker->next = path1;
                path1 = path1->next;
                tracker = tracker->next;
            }
            
            else{
                tracker->next = path2;
                path2 = path2->next;
                tracker = tracker->next;
            }
        }
        return head;
    } 
    
    else {
        head = l2;
        tracker =  l2;
        path1 = l1;
        path2 = l2->next;
        while (!(path1 == NULL && path2 == NULL)){
            if (path1 == NULL && path2 != NULL){
                tracker->next = path2;
                path2 = path2->next;
                tracker = tracker->next;
            }
            
            else if (path1 != NULL && path2 == NULL){
                tracker->next = path1;
                path1 = path1->next;
                tracker = tracker->next;
            }
            
            else if (path1->val <= path2->val){
                tracker->next = path1;
                path1 = path1->next;
                tracker = tracker->next;
            }
            
            else{
                tracker->next = path2;
                path2 = path2->next;
                tracker = tracker->next;
            }
        }
        return head;
    } 
}