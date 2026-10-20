class Solution {
public:

    bool inbet(int x, int y, int a, int b){
        return ((a<=x && b>=x)&&(a<=y && b>=y));
    }
    
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        if(*min_element(nums.begin(), nums.end()) > b) return 0;
        if(*max_element(nums.begin(), nums.end()) < a) return 0;
        int cnt =0;
        for(int i=0; i<nums.size()-1;i++){
            for(int j=0;j<nums.size()-1-i;j++){
                if(nums[j]>nums[j+1] && !inbet(nums[j], nums[j+1],a,b)){
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
