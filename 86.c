/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* create(int data);
    struct ListNode *l,*g,*l_tracker,*g_tracker,*h_tracker,*l_tile,*l_head,*g_head;
    if (head == NULL || head->next == NULL) return head;
    l = create(-1);
    g = create(-1);
    l_tracker = l;
    g_tracker = g;
    h_tracker = head;
    l_tile = NULL;
    while (h_tracker){
        if (h_tracker->val < x){
            struct ListNode *new_node = create(h_tracker->val);
            l_tracker->next = new_node;
            l_tracker = l_tracker->next;
            h_tracker = h_tracker->next;
            if (l_tracker->next == NULL) l_tile = l_tracker;
        }
        else {
            struct ListNode *new_node = create(h_tracker->val);
            g_tracker->next = new_node;
            g_tracker = g_tracker->next;
            h_tracker = h_tracker->next;
        }
    }
    l_head = l->next;
    g_head = g->next;
    if (l_head == NULL && g_head != NULL) return g_head;
    if (l_head != NULL && g_head == NULL) return l_head;
    l_tile->next = g_head;
    return l_head;
}

struct ListNode* create(int data){
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->next = NULL;
    new_node->val =  data;
    return new_node;
}