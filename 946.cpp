class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> my_stack;
        int i = 0;
        int j = 0;
        int n = pushed.size();
        for (i=0;i<n;i++){
            my_stack.push(pushed[i]);
            while (!my_stack.empty() and my_stack.top() == popped[j]){
                my_stack.pop();
                j++;
            }
        }
        if (j == n) return true;
        else return false;
    }
};