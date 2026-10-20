class Solution {
public:
    long long mod = 1e9+7;
    
    long long power(long long base, long long exp){
        long long res = 1;
        base = base % mod;
        while(exp>0){
            if(exp%2==1) res = (res*base)%mod;
            exp = exp/2;
            base = (base*base)%mod;
        } 
        return res;
    }

    int countGoodNumbers(long long n) {
        long long odd_positions = n/2;
        long long even_positions = (n+1)/2;
        
        long long even_comb = power(5, even_positions);
        long long odd_comb = power(4, odd_positions);
        return (even_comb * odd_comb) % mod;
    }
};
