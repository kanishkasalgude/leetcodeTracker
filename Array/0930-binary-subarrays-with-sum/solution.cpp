class Solution {
    int func(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int l = 0;
        int r = 0;
        long long sum = 0;
        int cnt = 0;
        while(r<nums.size()){
            sum += nums[r];
            while(sum > goal){
                sum = sum - (long long)nums[l];
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums, goal) - func(nums, goal - 1);
    }
};
