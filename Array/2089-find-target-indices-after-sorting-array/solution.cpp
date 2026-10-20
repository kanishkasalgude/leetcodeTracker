class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less_count = 0;
        int target_count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target) less_count++;
            else if(nums[i] == target) target_count++; 
        }

        vector<int> result;
        for(int i=0;i<target_count;i++){
            result.push_back(less_count+i);
        }
        return result;
    }
};
