/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *tracker,*prev;
    prev = NULL;
    tracker = head;
    while(tracker){
        struct ListNode* next_temp = tracker->next;
        tracker->next = prev;
        prev = tracker;
        tracker = next_temp;
    }
    return prev;
}