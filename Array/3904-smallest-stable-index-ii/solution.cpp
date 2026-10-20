class Solution {
    void findNsee(vector<int> &nsee, vector<int>& nums){
        for(int i = nums.size()-1; i>=0;i--){
            if(i == nums.size()-1) nsee[i] = nums[i];
            else nsee[i] = min(nums[i], nsee[i+1]);
        }
    }

    void findPlee(vector<int> &plee, vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(i == 0) plee[i] = nums[i];
            else plee[i] = max(plee[i-1], nums[i]);
        }
    }
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> plee(n,-1);
        vector<int> nsee(n,-1);
        findPlee(plee, nums);
        findNsee(nsee, nums);
        for(int i=0; i<n; i++){
            if((plee[i] - nsee[i]) <= k){
                return i;
            }
        }
        return -1;
    }
};
