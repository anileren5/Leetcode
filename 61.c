/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* rotate(struct ListNode* head);
    int i;
    if (!head || length(head) == 1) return head;
    for (i=0;i<(k%length(head));i++) head = rotate(head);
    return head;
}


struct ListNode* rotate(struct ListNode* head){
    struct ListNode* nth_node(struct ListNode* head,int n);
    int length(struct ListNode* head);
    struct ListNode*  old_head = head;
    struct ListNode*  old_tail = nth_node(head,length(head)-1);
    struct ListNode*  pre_tail = nth_node(head,length(head)-2);
    pre_tail->next = NULL;
    old_tail->next = old_head;
    return old_tail;
}


int length(struct ListNode* head){
    int n = 0;
    struct ListNode* tracker = head;
    while (tracker){
        n++;
        tracker = tracker->next;
    }
    return n;
}

struct ListNode* nth_node(struct ListNode* head,int n){
    int i;
    struct ListNode* tracker = head;
    for (i=0;i<n;i++) tracker = tracker->next;
    return tracker;
}