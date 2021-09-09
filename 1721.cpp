/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct ListNode* swapNodes(struct ListNode* head, int k){
        /*struct ListNode* nth_node(struct ListNode* head, int n);
        int length(struct ListNode* head);*/
        int l = length(head);
        int temp = nth_node(head,k-1)->val;
        nth_node(head,k-1)->val = nth_node(head,l-k)->val;
        nth_node(head,l-k)->val = temp;
        return head;
    }

    struct ListNode* nth_node(struct ListNode* head,int n){
        struct ListNode *tracker;
        int i;
        tracker = head;
        for (i=0;i<n;i++) tracker = tracker->next;
        return tracker;
    }

    int length(struct ListNode* head){
        struct ListNode* tracker;
        int l = 0;
        tracker= head;
        while (tracker){
            l++;
            tracker = tracker->next;
        }
        return l;
    }
};