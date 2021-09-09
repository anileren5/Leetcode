/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode* create(int data);
    struct ListNode *e,*o,*e_tracker,*o_tracker,*l_tracker,*e_tail,*even_head,*odd_head;
    if (!head) return head;
    int i = 0;
    e = create(-1);
    o = create(-1);
    e_tracker = e;
    o_tracker = o;
    l_tracker = head;
    e_tail = NULL;
    while(l_tracker){
        if ((i)%2 == 0){
            struct ListNode *new_node = create(l_tracker->val);
            e_tracker->next = new_node;
            e_tracker = e_tracker->next;
            l_tracker = l_tracker->next;
            if (o_tracker->next == NULL) e_tail = e_tracker; 
            i++;
        }
        
        else {
            struct ListNode *new_node = create(l_tracker->val);
            o_tracker->next = new_node;
            o_tracker = o_tracker->next;
            l_tracker = l_tracker->next;
            i++;
        }
    }
    even_head = e->next;
    odd_head = o->next;
    e_tail->next = odd_head;
    return even_head;
}

struct ListNode* create(int data){
    struct ListNode* new_node;
    new_node = malloc(sizeof(struct ListNode));
    new_node->val = data;
    new_node->next = NULL;
    return new_node;
}