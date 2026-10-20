class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX;
        int min_even = INT_MAX;

        for(int x : nums1){
            if(x%2 != 0){
                min_odd = min(min_odd, x);
            }else{
                min_even = min(min_even, x);
            }
        }

        if(min_odd == INT_MAX || min_even == INT_MAX){
            return true;
        }

        return min_odd<min_even;
    }
};
