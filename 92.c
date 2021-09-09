/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* reverse(struct ListNode* head);
    struct ListNode* tail(struct ListNode* head);
    struct ListNode* nth_node(struct ListNode* head,int n);
    struct ListNode *pre,*post,*part_head,*part_tail;
    if (left == 1){
        struct ListNode *post;
        post = nth_node(head,right);
        nth_node(head,right-1)->next = NULL;
        part_head = reverse(nth_node(head,0));
        part_tail = tail(part_head);
        part_tail->next = post;
        return part_head; 
    }
    pre = nth_node(head,left-2);
    post = nth_node(head,right);
    nth_node(head,right-1)->next = NULL;
    part_head = reverse(nth_node(head,left-1));
    part_tail = tail(part_head);
    pre->next = part_head;
    part_tail->next = post;
    return head;
}

struct ListNode* reverse(struct ListNode* head){
    struct ListNode *tracker,*prev;
    prev = NULL;
    tracker = head;
    while (tracker){
        struct ListNode* temp_next = tracker->next;
        tracker->next = prev;
        prev = tracker;
        tracker = temp_next;
    }
    return prev;
}

struct ListNode* tail(struct ListNode* head){
    struct ListNode* tracker = head;
    while (tracker->next) tracker = tracker->next;
    return tracker;
}

struct ListNode* nth_node(struct ListNode* head,int n){
    struct ListNode* tracker = head;
    int i;
    for (i=0;i<n;i++) tracker = tracker->next;
    return tracker;
}

int length(struct ListNode* head){
    struct ListNode* tracker = head;
    int n = 0;
    while (tracker) {
        tracker = tracker->next;
        n++;
    }
    return n;
}