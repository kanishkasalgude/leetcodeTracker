class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum > maxi){
                maxi = sum;
                cnt++;
            }
            if(sum < 0) sum = 0;
        }
        if(cnt == 0 && maxi < 0) maxi = 0;
        return maxi;
    }
};
