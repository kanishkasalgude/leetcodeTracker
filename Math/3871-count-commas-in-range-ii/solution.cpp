class Solution {
public:
    long long countCommas(long long n) {
        long long sum = 0;
        if(n == 1e15) sum++;
        if(n >= 1e12) sum = sum + (n - 1e12 +1);
        if(n >= 1e9) sum = sum + (n - 1e9 +1);
        if(n >= 1e6) sum = sum + (n - 1e6 + 1);
        if(n >= 1e3) sum = sum + (n - 1e3 + 1);
        return sum;
        //1,000,000,000,000,000
    }
};
