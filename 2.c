/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* create(int data);
    struct ListNode *tracker1,*tracker2,*pre_head,*s_tracker;
    int carry;
    tracker1 = l1;
    tracker2 = l2;
    carry = 0;
    pre_head = create(-1);
    s_tracker = pre_head;
    while (!(tracker1 == NULL && tracker2 == NULL)){
        if (tracker1!=NULL && tracker2!=NULL){
            struct ListNode* new_node = create(-1); 
            int sum = tracker1->val + tracker2->val + carry;
            int digit = sum % 10;
            carry = sum / 10;
            new_node->val = digit;
            s_tracker->next = new_node;
            s_tracker = s_tracker->next;
            tracker1 = tracker1->next;
            tracker2 = tracker2->next;
        }
        
        else if (tracker1==NULL && tracker2!=NULL){
            struct ListNode* new_node = create(-1);
            int sum = tracker2->val + carry;
            int digit = sum%10;
            carry = sum/10;
            new_node->val = digit;
            s_tracker->next = new_node;
            s_tracker = s_tracker->next;
            tracker2 = tracker2->next;
        }
        
        else if (tracker1!=NULL && tracker2==NULL){
            struct ListNode* new_node = create(-1);
            int sum = tracker1->val + carry;
            int digit = sum%10;
            carry = sum/10;
            new_node->val = digit;
            s_tracker->next = new_node;
            s_tracker = s_tracker->next;
            tracker1 = tracker1->next;
        }
    }
    
    if (carry!=0){
        struct ListNode* new_node = create(carry);
        s_tracker->next = new_node;
    }
    
    
    return pre_head->next;
}


struct ListNode* create(int data){
    struct ListNode* new_node;
    new_node = malloc(sizeof(struct ListNode));
    new_node->next = NULL;
    new_node->val = data;
    return new_node;
}