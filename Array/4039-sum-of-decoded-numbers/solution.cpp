class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        long long mod = 1e9+7;
        long long total_sum = 0;
        for(long long num : nums){
            int width = num % 10;
            long long d_i = num/10;
            string s = to_string(d_i);
            long long x_i = stoll(s.substr(0,width));
            long long y_i = stoll(s.substr(width));

            long long current_val = 1;
            x_i = x_i%mod;
            while(y_i > 0){
                if(y_i%2 == 1){
                    current_val = (current_val*x_i)%mod;
                }
                x_i = (x_i*x_i)%mod;
                y_i /= 2;
            }
            total_sum = (total_sum + current_val)%mod;
        }
        return total_sum;
    }
};
