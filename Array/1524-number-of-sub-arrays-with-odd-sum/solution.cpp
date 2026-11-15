class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7;
        int parity_check = 0;
        long long even_count = 1;
        long long odd_count = 0;
        long long ans = 0;
        for(auto num:arr){
            parity_check ^= (num&1);
            if(parity_check == 1){
                ans = (ans + even_count)%mod;
                odd_count++;
            }else{
                ans = (ans + odd_count)%mod;
                even_count++;
            }
        }
        return ans%mod;
    }
};
