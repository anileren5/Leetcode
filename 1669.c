/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    int length(struct ListNode *head);
    struct ListNode* nth_node(struct ListNode* head,int n);
    struct ListNode *pre,*post,*beg,*end;
    pre = nth_node(list1,a-1); 
    post = nth_node(list1,b+1);
    beg = list2;
    end = nth_node(list2,length(list2)-1);
    pre->next = beg;
    end->next = post;
    return list1;
}

struct ListNode* nth_node(struct ListNode *head,int n){
    int i;
    struct ListNode* tracker = head;
    for (i=0;i<n;i++){
        tracker = tracker->next;
    }
    return tracker;
}

int length(struct ListNode *head){
    int n = 0;
    struct ListNode* tracker = head;
    while (tracker){
        n++;
        tracker = tracker->next;
    }
    return n;
}