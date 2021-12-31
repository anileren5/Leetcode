class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int i=0;i<stones.size();i++) maxHeap.push(stones[i]);
        
        while (maxHeap.size() > 1){
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            
            if (y == x) continue;
            else maxHeap.push(y-x);
        }
        
        if (maxHeap.size() == 0) return 0;
        else return maxHeap.top();
    }
};