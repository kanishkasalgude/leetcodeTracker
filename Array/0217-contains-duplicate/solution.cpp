#include<unordered_set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>us;
        for(int i=0;i<nums.size();i++){
            if(us.contains(nums[i])) return true;
            else us.insert(nums[i]);
        }
        return false;
    }
};
