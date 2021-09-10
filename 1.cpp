class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        bool is_found = false;
        for (int i=0;i<nums.size();i++){
            for (int j=i+1;j<nums.size();j++){
                if ((nums[i]+nums[j]) == target){
                    is_found = true;
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
                if (is_found == true) break;
            }
        }
        return result;
    }