class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target){
                if(start<i) res = min(i-start, res);
                else res = min(start - i, res);
            }
        }
        return res;
    }
};
