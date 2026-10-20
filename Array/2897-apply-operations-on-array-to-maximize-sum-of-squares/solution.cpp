class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCount(31,0);
        for(int num:nums){
            for(int i=0;i<31;i++){
                if((num>>i)&1) bitCount[i]++;
            }
        }

        long long res = 0;
        long long mod = 1e9+7;
        for(int i=0;i<k;i++){
            long long currentNum = 0;
            for(int bit = 0; bit<31;bit++){
                if(bitCount[bit] > 0){
                    currentNum |= (1LL<<bit);
                    bitCount[bit]--;
                }
            }
            res = (res+(currentNum*currentNum)%mod)%mod;
        }

        return res;
    }
};
