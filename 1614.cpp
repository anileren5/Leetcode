class Solution {
public:
    int maxDepth(string s) {
        int i=0;
        int current_depth = 0;
        int max_depth = 0;
        
        for (i=0;i<s.size();i++){
            char current_token = s[i];
            if (current_token == '('){
                current_depth++;
                if (current_depth > max_depth) max_depth = current_depth;
            }
            else if (current_token == ')') current_depth--;
        }
        return max_depth;
    }
    
};