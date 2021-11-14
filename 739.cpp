class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int i,l = temperatures.size();
        vector<int> answer(l,0);
        stack<vector<int>> mystack;
        for (i=0;i<l;i++){
            vector<int> current_day{i,temperatures[i]};
            while (1){
                if (mystack.empty()){
                    mystack.push(current_day);
                    break;
                }
                else {
                    if (temperatures[i] > mystack.top()[1]){
                        answer[mystack.top()[0]] = i - mystack.top()[0];
                        mystack.pop();
                    }
                    else{
                        mystack.push(current_day);
                        break;
                    }
                }
            }
        }
        return answer;
    }
};