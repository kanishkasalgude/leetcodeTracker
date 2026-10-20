#include <bits/stdc++.h>
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]== val){
                cnt++;
            } 
        }
        for(int i=0; i<cnt; i++){
            nums.erase(find(nums.begin(), nums.end(), val));
        }
        return nums.size();
    }
};
