class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        int index1 = 0;
        int index2 = 1;
        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                ans[index2] = nums[i];
                index2 += 2;
            }
            else{
                ans[index1] = nums[i];
                index1 += 2;
            }
        }
        return ans;
    }
};
