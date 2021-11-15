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
    bool isPalindrome(ListNode* head) {
        bool flag = true;
        stack<int> stack1;
        stack<int> stack2;
        ListNode* tracker = head;
        int i,n = 0;
        while (tracker){
            n++;
            stack1.push(tracker->val);
            tracker = tracker->next;
        }
        if (n==0 or n==1) return true;
        if (n%2 == 0){
            for (i=0;i<n/2;i++){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        else {
            for (i=0;i<((n-1)/2);i++){
                stack2.push(stack1.top());
                stack1.pop();
            }
            stack1.pop();
        }
        
        while (!stack1.empty() and !stack2.empty()){
            if (stack1.top() != stack2.top()){
                flag = false;
                break;
            }
            else{
                stack1.pop();
                stack2.pop();
            }
        }
        return flag;
        
    }
};