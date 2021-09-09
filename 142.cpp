/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head){
        vector<ListNode*> past_nodes;
        ListNode* result = nullptr;
        ListNode* tracker = head;
        while (tracker){
            past_nodes.push_back(tracker);
            if (tracker->next != nullptr){
                if (is_pastNode(tracker->next,past_nodes)){
                    result = tracker->next;
                    break;
                }
            }
            tracker = tracker->next;
        }
        return result;
    }
    
    bool is_pastNode(ListNode* node,vector<ListNode*> past_nodes){
        bool flag = false;
        for (auto p_node : past_nodes) if (node == p_node) flag = true;
        return flag;
    }
};