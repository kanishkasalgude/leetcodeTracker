class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin() , nums.end());
        int high = 0;
        int mid;
        for(int i=0;i<nums.size();i++){
            high+=nums[i];
        }
        while(low<= high){
            mid = low + (high - low)/2;;
            if(isValid(nums, k, mid) == true){
                high = mid - 1;
            }else low = mid + 1;
        }
        return low;
    }

    bool isValid(vector<int>& nums, int k, int barrier){
        int breaks = 1; int sum = 0;
        for(int i=0; i<nums.size();i++){
            if(nums[i] > barrier) return false;
            if(nums[i] + sum > barrier){
                sum = nums[i];
                breaks++;
            }else{
                sum+=nums[i];
            }
        }
        if(breaks > k) return false;
        return true;
    }
};
