class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // If s is shorter than t, it can't contain t as a subsequence
        if (m < n) return 0;

        // dp[j] stores the count of distinct subsequences of t[0...j-1] in s
        // Using unsigned long long to prevent integer overflow during intermediate additions
        vector<unsigned long long> dp(n + 1, 0);
        
        // Base case: empty string t can always be formed in 1 way
        dp[0] = 1;

        for (char c : s) {
            for (int j = n; j >= 1; --j) {
                if (c == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};
